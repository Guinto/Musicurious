import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class AudioInformation {

	private String audioFileName;
	
	public AudioInformation(String audioFileName) {
		this.audioFileName = audioFileName;
		readFiles();
	}
	
	public void readFiles() {
		readLoudnessFile();
		readPitchFile();
	}
	
	public void readLoudnessFile() {
		ArrayList<Float> values = new ArrayList<Float>();
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
				values.add(Float.parseFloat(valuesInLine[i]));
			}
		}
		System.out.println(values);
	}
	
	public void readPitchFile() {
		
	}
}
