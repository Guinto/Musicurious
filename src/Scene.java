import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.ArrayList;

import javax.swing.JFrame;
import javax.swing.JSlider;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

public class Scene extends JFrame implements ChangeListener {

	private AudioPlayer audioPlayer;
	private Board board;
	
	public Scene() {
		audioPlayer = new AudioPlayer();
		audioPlayer.setVolume(0.7f);
		audioPlayer.setSourceLocation("audio/test_2.mp3");
		
		ArrayList<AudioInformation> instrumentInfos = new ArrayList<AudioInformation>();
		
		String audioFileName = "audio/test_2.mp3";
		String hackedFileName = audioFileName.substring(0, audioFileName.length() - 4) + "_piano.wav";
		AudioInformation pianoInfo = new AudioInformation(hackedFileName);
		pianoInfo.setAudioPlayer(audioPlayer);
		
		hackedFileName = audioFileName.substring(0, audioFileName.length() - 4) + "_guitar.wav";
		AudioInformation guitarInfo = new AudioInformation(hackedFileName);
		guitarInfo.setAudioPlayer(audioPlayer);
		
		instrumentInfos.add(pianoInfo);
		instrumentInfos.add(guitarInfo);
		
		board = new Board(instrumentInfos);
		add(board);
		addKeyListener(new BoardKeyListener(board));

		JFrame f = new JFrame();
		f.setSize(300, 100);
		JSlider sizeSlider = new JSlider(0, 100, 0);
		f.add(sizeSlider);
		sizeSlider.addChangeListener(this);
		f.setVisible(true);
		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setSize(1280, 720);
		setLocationRelativeTo(null);
		setTitle("Scene");
		setResizable(false);
		setVisible(true);
	}

	public void playAudio() {
		audioPlayer.play();
	}

	class BoardKeyListener implements KeyListener {
		private Board board;

		public BoardKeyListener(Board board) {
			this.board = board;
		}

		@Override
		public void keyTyped(KeyEvent e) {
		}

		@Override
		public void keyReleased(KeyEvent e) {
			if (e.getKeyChar() == ' ') {
				board.play();
				try {
					Thread.sleep(90);
				} catch (InterruptedException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
				playAudio();
			}
		}

		@Override
		public void keyPressed(KeyEvent e) {
		}

	}

	@Override
	public void stateChanged(ChangeEvent e) {
        JSlider source = (JSlider)e.getSource();
        int size = (int)source.getValue();
        for (Instrument instrument : board.getInstruments()) {
        	instrument.setSize(size);
        }
	}
}
