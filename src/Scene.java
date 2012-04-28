import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

import javax.swing.JFrame;


public class Scene extends JFrame {

	public Scene(AudioInformation audioInfo) {
		
		Board board = new Board(audioInfo);
		add(board);
		
		addKeyListener(new BoardKeyListener(board));
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(1280, 720);
        setLocationRelativeTo(null);
        setTitle("Scene");
        setResizable(false);
        setVisible(true);
	}
	
	public void playAudio() {
		AudioPlayer audioPlayer = new AudioPlayer();
		audioPlayer.setVolume( 0.7f );
		audioPlayer.setSourceLocation("audio/test.mp3");
		audioPlayer.play();
	}
	
	class BoardKeyListener implements KeyListener {
		private Board board;
		
		public BoardKeyListener(Board board) {
			this.board = board;
		}
		
		@Override
		public void keyTyped(KeyEvent e) { }
		
		@Override
		public void keyReleased(KeyEvent e) {
			if (e.getKeyChar() == ' ') {
				board.play();
				playAudio();
			}
		}
		
		@Override
		public void keyPressed(KeyEvent e) { }
		
	}
}
