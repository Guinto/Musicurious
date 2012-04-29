import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Toolkit;

import javax.swing.JPanel;


public class Board extends JPanel implements Runnable {

    private Instrument instrument;
    private Thread animator;
    private boolean playIsPressed, playing;

    private final int DELAY = 50 / 3;

    public Board(AudioInformation audioInfo) {
        setBackground(Color.BLACK);
        setDoubleBuffered(true);

        instrument = new Instrument();
        instrument.setImage("sprites/23G.png");
        instrument.setAudioInformation(audioInfo);
        
        playIsPressed = playing = false;
    }

    public void addNotify() {
        super.addNotify();
        animator = new Thread(this);
        animator.start();
    }

    public void paint(Graphics g) {
        super.paint(g);

        Graphics2D g2d = (Graphics2D)g;
        g2d.drawImage(instrument.getImage(), instrument.getX(), instrument.getY(), 
        			  instrument.getWidth(), instrument.getHeight(), this);
        Toolkit.getDefaultToolkit().sync();
        g.dispose();
    }

    public void play() {
    	playIsPressed = true;
    }
    
    public void cycle(long timeElapsed) {
    	if (playIsPressed) {
    		instrument.getAudioInformation().resetIterators();
    		playing = true;
    		playIsPressed = false;
    	}
    	if (playing) {
    		instrument.update(timeElapsed);
    	}
    }
    
    public void run() {
        long beforeTime, timeDiff = 0, sleep;
   		beforeTime = System.currentTimeMillis();

        while (true) {
            cycle(timeDiff);
            repaint();

            timeDiff = System.currentTimeMillis() - beforeTime;
            sleep = DELAY - timeDiff;

            beforeTime = System.currentTimeMillis();
            try {
                Thread.sleep(Math.abs(sleep));
            } catch (InterruptedException e) {
                System.out.println("interrupted");
            }
    	}
    }
}