
	
import maryb.player.Player;

public class AudioPlayer {

	private Player player;
	
	public AudioPlayer() {
        player = new Player();
	}
	
	public void setSourceLocation(String url) {
        player.setSourceLocation(url);
	}
	
	public void play() {
		player.play();
	}
	
	public void setVolume(float volume) {
        player.setCurrentVolume(volume);
    }
}
