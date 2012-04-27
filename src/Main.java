

public class Main {

	private final String audioFileName = "audio/test.mp3";
	
	public static void main(String[] args) {
		Main runner = new Main();
		//runner.playAudio();
		runner.getAudioInformation();
	}
	
	public void getAudioInformation() {
		String hackedFileName = audioFileName.substring(0, audioFileName.length() - 3) + "wav";
		new AudioInformation(hackedFileName);
	}
	
	public void playAudio() {
		AudioPlayer audioPlayer = new AudioPlayer();
		audioPlayer.setVolume( 0.7f );
		audioPlayer.setSourceLocation(audioFileName);
		audioPlayer.play();
	}

}
