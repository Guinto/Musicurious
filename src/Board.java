import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Point;
import java.awt.Toolkit;
import java.util.ArrayList;
import java.util.Timer;
import java.util.TimerTask;

import javax.swing.JPanel;

public class Board extends JPanel {

	private ArrayList<Instrument> instruments;
	private boolean playIsPressed, playing;
	private Timer timer;

	public Board(ArrayList<AudioInformation> instrumentInfos) {
		
		setBackground(Color.BLACK);
		setDoubleBuffered(true);
		instruments = new ArrayList<Instrument>();

		Instrument piano = new Instrument();
		piano.setPoint(new Point(200, 0));
		piano.setImage("sprites/23G.png");
		piano.setAudioInformation(instrumentInfos.get(0));
		instruments.add(piano);
		
		Instrument guitar = new Instrument();
		guitar.setImage("sprites/105G.png");
		guitar.setPoint(new Point(900, 0));
		guitar.setAudioInformation(instrumentInfos.get(1));
		instruments.add(guitar);

		playIsPressed = playing = false;

		timer = new Timer();
		timer.scheduleAtFixedRate(new ScheduleTask(), 0, 10);
	}
	
	class ScheduleTask extends TimerTask {

		public void run() {
			for (Instrument instrument : instruments) {
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
	}

	public void paint(Graphics g) {
		super.paint(g);

		Graphics2D g2d = (Graphics2D) g;
		for (Instrument instrument : instruments) {
			g2d.drawImage(instrument.getImage(), instrument.getX(), instrument.getY(), 
					instrument.getWidth(), instrument.getHeight(), this);
		}
		Toolkit.getDefaultToolkit().sync();
		g.dispose();
	}

	public void play() {
		playIsPressed = true;
	}

	public ArrayList<Instrument> getInstruments() {
		return instruments;
	}
}