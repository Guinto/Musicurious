import java.awt.Image;
import java.awt.Point;

import javax.swing.ImageIcon;


public class Instrument {

	private ImageIcon imageIcon;
	private Point point;
	private AudioInformation audioInfo;
	
	public Instrument() {
		point = new Point(10, 10);
	}
	
	public void setImage(String fileName) {
		imageIcon = new ImageIcon(fileName);
	}
	
	public Image getImage() {
		return imageIcon.getImage();
	}
	
	public void update(float timeElapsed) {
		point.x += 1;
        point.y += 1;

        if (point.x > 240) {
            point.y = -45;
            point.x = -45;
        }
        
        System.out.println(timeElapsed);
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
}
