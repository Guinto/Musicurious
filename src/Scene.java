import javax.swing.JFrame;


public class Scene extends JFrame {

	public Scene(AudioInformation audioInfo) {
		
		add(new Board(audioInfo));
		
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(1280, 720);
        setLocationRelativeTo(null);
        setTitle("Scene");
        setResizable(false);
        setVisible(true);
	}
}
