import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Toolkit;
import java.util.Timer;
import java.util.TimerTask;

import javax.swing.JPanel;

public class Board extends JPanel {

	private Instrument instrument;
	private boolean playIsPressed, playing;
	private Timer timer;

	private final int DELAY = 50 / 3;

	public Board(AudioInformation audioInfo) {
		setBackground(Color.BLACK);
		setDoubleBuffered(true);

		instrument = new Instrument();
		instrument.setImage("sprites/23G.png");
		instrument.setAudioInformation(audioInfo);

		playIsPressed = playing = false;

		timer = new Timer();
		timer.scheduleAtFixedRate(new ScheduleTask(), 0, 10);
	}

	class ScheduleTask extends TimerTask {

		public void run() {
			if (playIsPressed) {
				instrument.getAudioInformation().resetIterators();
				playing = true;
				playIsPressed = false;
			}
			if (playing) {
				instrument.update(10);
			}
			repaint();
		}
	}

	public void paint(Graphics g) {
		super.paint(g);

		Graphics2D g2d = (Graphics2D) g;
		g2d.drawImage(instrument.getImage(), instrument.getX(),
				instrument.getY(), instrument.getWidth(),
				instrument.getHeight(), this);
		Toolkit.getDefaultToolkit().sync();
		g.dispose();
	}

	public void play() {
		playIsPressed = true;
	}
}