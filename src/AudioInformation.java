import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class AudioInformation {

	private String audioFileName;
	private ArrayList<Float> loudnessValues, pitchValues;
	
	public AudioInformation(String audioFileName) {
		this.audioFileName = audioFileName;
		readFiles();
	}
	
	public void readFiles() {
		readLoudnessFile();
		readPitchFile();
	}
	
	public void readLoudnessFile() {
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
	
	public void readPitchFile() {
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
}
