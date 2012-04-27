

public class Main {

	public static void main(String[] args) {
		Main runner = new Main();
		runner.playAudio();
	}
	
	public void playAudio() {
		AudioPlayer audioPlayer = new AudioPlayer();
		audioPlayer.setVolume( 0.7f );
		audioPlayer.setSourceLocation("audio/09 Crummy.mp3");
		audioPlayer.play();
	}

}
