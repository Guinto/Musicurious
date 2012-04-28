import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Map;
import java.util.Scanner;

import javax.sound.sampled.AudioFileFormat;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.UnsupportedAudioFileException;

import org.tritonus.share.sampled.file.TAudioFileFormat;

public class AudioInformation {

	private String audioFileName;
	private ArrayList<Float> loudnessValues, pitchValues;
	private Iterator<Float> loudnessIterator, pitchIterator;
	
	public AudioInformation(String audioFileName) {
		this.audioFileName = audioFileName;
		readFiles();
		setIterators();
	}
	
	/**
	 * Using a library called MP3SPI
	 * Found here: http://www.javazoom.net/mp3spi/documents.html
	 */
	private int getDurationWithMp3Spi(File file) throws UnsupportedAudioFileException, IOException {
		int mili = -1;
		
	    AudioFileFormat fileFormat = AudioSystem.getAudioFileFormat(file);
	    if (fileFormat instanceof TAudioFileFormat) {
	        Map<?, ?> properties = ((TAudioFileFormat) fileFormat).properties();
	        String key = "duration";
	        Long microseconds = (Long) properties.get(key);
	        mili = (int) (microseconds / 1000);
	    } else {
	        throw new UnsupportedAudioFileException();
	    }

	    return mili;
	}
	
	public int getAudioLength() {
		String hackedFileName = audioFileName.substring(0, audioFileName.length() - 3) + "mp3";
		
		try {
			return getDurationWithMp3Spi(new File(hackedFileName));
		} catch (Exception e) {
			e.printStackTrace();
		} 
		
		return -1;
	}
	
	public boolean hasNextPitch() {
		return pitchIterator.hasNext();
	}
	
	public float getNextPitch(float timeElapsed) {
		return pitchIterator.next();
	}
	
	public float getPitchSize() {
		return pitchValues.size();
	}
	
	public boolean hasNextLoudness() {
		return loudnessIterator.hasNext();
	}

	public float getNextLoudness(float timeElapsed) {
		return loudnessIterator.next();
	}
	
	public int getLoudnessSize() {
		return loudnessValues.size();
	}
	
	private void readFiles() {
		readLoudnessFile();
		readPitchFile();
	}
	
	private void readLoudnessFile() {
		loudnessValues = new ArrayList<Float>();
		String loudnessFileName = audioFileName + ".lx.csv";
		
		Scanner scanner = null;
		
		try {
			scanner = new Scanner(new File(loudnessFileName));
		} catch (FileNotFoundException e) {
			System.err.println("FILE " + loudnessFileName + " NOT FOUND");
		}
		
		while (scanner.hasNextLine()) {
			String line = scanner.nextLine();
			if (line.contains("%")) {
				continue;
			}
			String[] valuesInLine = line.split("[,]");
			for (int i = 0; i < valuesInLine.length; i++) {
				loudnessValues.add(Float.parseFloat(valuesInLine[i]));
			}
		}
	}
	
	private void readPitchFile() {
		pitchValues = new ArrayList<Float>();
		String pitchFileName = audioFileName + ".pitch";
		
		Scanner scanner = null;
		
		try {
			scanner = new Scanner(new File(pitchFileName));
		} catch (FileNotFoundException e) {
			System.err.println("FILE " + pitchFileName + " NOT FOUND");
		}
		
		while (scanner.hasNextFloat()) {
			pitchValues.add(scanner.nextFloat());
		}
	}
	
	private void setIterators() {
		pitchIterator = pitchValues.iterator();
		loudnessIterator = loudnessValues.iterator();
	}
}
