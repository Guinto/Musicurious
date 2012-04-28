import javax.swing.JFrame;


public class Scene extends JFrame {

	public Scene(AudioInformation audioInfo) {
		
		add(new Board(audioInfo));
		
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(600, 800);
        setLocationRelativeTo(null);
        setTitle("Scene");
        setResizable(false);
        setVisible(true);
	}
}
