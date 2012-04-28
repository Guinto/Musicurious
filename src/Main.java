

public class Main {

	private final String audioFileName = "audio/test.mp3";
	
	public static void main(String[] args) {
		Main runner = new Main();
		runner.playAudio();
		AudioInformation audioInfo = runner.getAudioInformation();
		runner.showVisual(audioInfo);
	}
	
	public void playAudio() {
		AudioPlayer audioPlayer = new AudioPlayer();
		audioPlayer.setVolume( 0.7f );
		audioPlayer.setSourceLocation(audioFileName);
		audioPlayer.play();
	}
	
	public AudioInformation getAudioInformation() {
		String hackedFileName = audioFileName.substring(0, audioFileName.length() - 3) + "wav";
		return new AudioInformation(hackedFileName);
	}
	
	public void showVisual(AudioInformation audioInfo) {
		new Scene(audioInfo);
	}

}
