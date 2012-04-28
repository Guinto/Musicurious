import java.awt.Image;
import java.awt.Point;

import javax.swing.ImageIcon;


public class Instrument {

	private ImageIcon imageIcon;
	private Point point;
	private AudioInformation audioInfo;
	private float totalPitchTime, totalLoudnessTime;
	
	public Instrument() {
		point = new Point(0, 0);
		totalPitchTime = totalLoudnessTime = 0;
	}
	
	public void setImage(String fileName) {
		imageIcon = new ImageIcon(fileName);
	}
	
	public Image getImage() {
		return imageIcon.getImage();
	}
	
	public void update(long timeElapsed) {
		//syncPitch(timeElapsed);
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
	}
	
	private void syncPitch(float timeElapsed) {
		if (audioInfo.hasNextPitch()) {
			float pitch = audioInfo.getNextPitch(timeElapsed);
			point.y = (int)pitch;
		}
	}
	
	private void syncLoudness(long timeElapsed) {
		if (timeElapsed > 0) {
			float iterationsPerMillisecond = audioInfo.getLoudnessSize() / audioInfo.getAudioLength();
			totalLoudnessTime += timeElapsed;
			float iterations = totalLoudnessTime * iterationsPerMillisecond;
			float leftOvers = iterations - (int)iterations;
			
			for (int i = 0; i < iterations; i++) {
				if (audioInfo.hasNextLoudness()) {
					float loudness = audioInfo.getNextLoudness(timeElapsed);
					point.x = (int)loudness * 100;
				}
			}
			totalLoudnessTime = leftOvers;
		}
	}
}
