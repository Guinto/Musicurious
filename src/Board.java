import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Toolkit;

import javax.swing.JPanel;


public class Board extends JPanel implements Runnable {

    private Instrument instrument;
    private Thread animator;

    private final int DELAY = 50;

    public Board(AudioInformation audioInfo) {
        setBackground(Color.BLACK);
        setDoubleBuffered(true);

        instrument = new Instrument();
        instrument.setImage("sprites/23G.png");
        instrument.setAudioInformation(audioInfo);
    }

    public void addNotify() {
        super.addNotify();
        animator = new Thread(this);
        animator.start();
    }

    public void paint(Graphics g) {
        super.paint(g);

        Graphics2D g2d = (Graphics2D)g;
        g2d.drawImage(instrument.getImage(), instrument.getX(), instrument.getY(), this);
        Toolkit.getDefaultToolkit().sync();
        g.dispose();
    }

    public void cycle(long timeElapsed) {
    	instrument.update(timeElapsed);
    }
    
    public void run() {

        long beforeTime, timeDiff = 0, sleep;

        beforeTime = System.currentTimeMillis();

        while (true) {

            cycle(timeDiff);
            repaint();

            timeDiff = System.currentTimeMillis() - beforeTime;
            sleep = DELAY - timeDiff;

            if (sleep < 0)
                sleep = 2;
            try {
                Thread.sleep(sleep);
            } catch (InterruptedException e) {
                System.out.println("interrupted");
            }

            beforeTime = System.currentTimeMillis();
        }
    }
}