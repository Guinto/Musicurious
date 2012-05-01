import java.awt.Image;
import java.awt.Point;

import javax.swing.ImageIcon;

public class Instrument {

	private ImageIcon imageIcon;
	private Point point;
	private AudioInformation audioInfo;
	private float totalPitchTime, totalLoudnessTime;
	private int width, height;
	private int size;

	public Instrument() {
		point = new Point(300, 0);
		totalPitchTime = totalLoudnessTime = 0;
	}

	public void setImage(String fileName) {
		imageIcon = new ImageIcon(fileName);
		width = imageIcon.getIconWidth();
		height = imageIcon.getIconHeight();
		size = 0;
	}

	public Image getImage() {
		return imageIcon.getImage();
	}

	public void update(long timeElapsed) {
		syncPitch(timeElapsed);
		syncLoudness(timeElapsed);
	}

	public int getX() {
		return point.x;
	}

	public int getY() {
		return point.y;
	}

	public void setAudioInformation(AudioInformation audioInfo) {
		this.audioInfo = audioInfo;
		point.y = 360 - (int)audioInfo.getPitchBegin();
	}

	private void syncPitch(float timeElapsed) {
		if (audioInfo.hasNextPitch()) {
			float iterationsPerMillisecond = audioInfo.getPitchSize() / audioInfo.getAudioLength();
			totalPitchTime += timeElapsed;
			float iterations = totalPitchTime * iterationsPerMillisecond;
			float leftOvers = iterations - (int)iterations;

			for (int i = 0; i < (int)iterations; i++) {
				if (audioInfo.hasNextPitch()) {
					float pitch = audioInfo.getNextPitch(timeElapsed);
					point.y = 360 - (int) pitch;
				}
			}
			if (iterations >= 1) {
				totalPitchTime -= (int)iterations / iterationsPerMillisecond;
				totalPitchTime += leftOvers / iterationsPerMillisecond;
			}
		}
	}

	private void syncLoudness(long timeElapsed) {
		if (audioInfo.hasNextLoudness()) {
			float iterationsPerMillisecond = audioInfo.getLoudnessSize() / audioInfo.getAudioLength(); 
			totalLoudnessTime += timeElapsed;
			float iterations = totalLoudnessTime * iterationsPerMillisecond;
			float leftOvers = iterations - (int) iterations;

			for (int i = 0; i < (int)iterations; i++) {
				if (audioInfo.hasNextLoudness()) {
					float loudness = audioInfo.getNextLoudness(timeElapsed);
					size = (int) loudness * 30;
				}
			}
			if (iterations >= 1) {
				totalLoudnessTime -= (int)iterations / iterationsPerMillisecond;
				totalLoudnessTime += leftOvers / iterationsPerMillisecond;
			}
		}
	}

	public int getWidth() {
		return width + size;
	}

	public int getHeight() {
		return height + size;
	}

	public AudioInformation getAudioInformation() {
		return audioInfo;
	}
}
