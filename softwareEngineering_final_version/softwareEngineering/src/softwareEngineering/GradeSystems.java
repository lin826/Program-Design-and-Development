/** *************************************************************************
class GradeSystems��HashmMap�s�xstudent grades.

containsID(ID)
GradeSystems ()
showGrade(ID)
showRank(ID)
updateWeights ()
checkReally(really,temp[])
getGrades(iD)
HashMap<String, Grades> getGrades()

 *************************************************************************** */

package softwareEngineering;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Scanner;


public class GradeSystems {
	private HashMap<String, Grades> grades = new HashMap<String, Grades>();
	private float[] weights = { (float) 0.1, (float) 0.1, (float) 0.1,
			(float) 0.3, (float) 0.4 };
	// (��l�� lab1 0.1, lab2 0.1, lab3 0.1, midTerm 0.3, finalExam 0.4)
	// (�`�Nweights ���M������1.0)
	private static Scanner input, scanner;
	private static String[] strItems = new String[5];
	{
		strItems[0] = "lab1�G               ";
		strItems[1] = "lab2�G               ";
		strItems[2] = "lab3�G               ";
		strItems[3] = "mid-term�G     ";
		strItems[4] = "final exam�G";
	}

/**
 *TODO ��aGradeSystem���_�t��ID
 *containsID(ID){
 *return containKey(ID)
 *}
 */
	// �x�s a list of student grades.
	public boolean containsID(String ID) {
		// ��aGradeSystem���_�t��ID
		return getGrades().containsKey(ID);
	}

/**
 * TODO �غc�l
 * GradeSystems (){
 *	File file = new File();
 * }
 */
	// Constructor
	public GradeSystems() throws FileNotFoundException {
		File file = new File("gradeinput.txt");
		String[] temp = new String[6];
		Grades tempGrades;
		input = new Scanner(file);

		while (input.hasNext()) {
			temp = input.nextLine().split(" ");
			tempGrades = new Grades(temp);
			getGrades().put(temp[0], tempGrades);
		}
		input.close();
	}

/**
 * TODO ��ܦ��Z �I�sGrades���p���`���Z
 * showGrade(ID){
 *   for (int i = 0; i < 5; i++)
 *		System.out.println(whichGrade[i] + thisStudent.Scores()[i]);
 *	float totalGrades = thisStudent.calculateTotalGrade(weights);
 * }
 * @param ID
 */
	// show the scores of the student
	public void showGrade(String ID) {
		Grades thisStudent = getGrades().get(ID);
		System.out.println(thisStudent.getStudentName() + "'s grades�G");
		for (int i = 0; i < 5; i++)
			System.out.println(strItems[i] + thisStudent.getScores()[i]);

		float totalGrades = thisStudent.calculateTotalGrade(weights);
		System.out.println("total grade�G" + totalGrades);
	}

/**
 * TODO ��ܱƦW
 * showRank(ID){
 *   int rank = 1;
 *	float thisTotalGrade = getGrades().get(ID).calculateTotalGrade(weights);
 *	for (Grades g : getGrades().values()) {
 *		if (thisTotalGrade < g.calculateTotalGrade(weights))
 *			rank++;
 *	}
 * }	
 */
	public void showRank(String ID) {
		int rank = 1;
		float thisTotalGrade = getGrades().get(ID).calculateTotalGrade(weights);
		for (Grades g : getGrades().values()) {
			if (thisTotalGrade < g.calculateTotalGrade(weights))
				rank++;
		}
		System.out.println(getGrades().get(ID).getStudentName() + "�ƦW��" + rank);
	}

/**
 * TODO ���s��J�t���B �T�{��J�s�t=>�I�scheck really
 * updateWeights (){
 *	for (int i = 0; i < 5; i++)
 *			System.out.println(strItems[i] + (int) (weights[i] * 100) + "%");
 *   while (!(really.equals("N") || really.equals("Y"))) {
 *			really = scanner.next();
 *			checkReally(really, temp);			
 *		}
 * }	
 */
	public void updateWeights() {
		int[] temp = new int[5];

		scanner = new Scanner(System.in);

		System.out.println("original weights");
		for (int i = 0; i < 5; i++)
			System.out.println(strItems[i] + (int) (weights[i] * 100) + "%");

		System.out.println("enter the new weights");

		for (int i = 0; i < 5; i++) {
			try {
				System.out.print(strItems[i]);
				temp[i] = Integer.parseInt(scanner.next());
			} catch (Exception e) {
				System.out.println("Illegal input");
				i--;
			}
		}

		System.out.println("please check the new weights");
		for (int i = 0; i < 5; i++)
			System.out.println(strItems[i] + temp[i] + "%");

		String really="";

		while (!(really.equals("N") || really.equals("Y"))) {
			System.out.println("Really?(Y/N)");
			really = scanner.next();
			checkReally(really, temp);			
		}

	}

/**
 *TODO �T�{��J���O�_�OY �O���ܴN��s���t����s
 *checkReally(really,temp[]){
 *   if (really.equals("Y")) {
 *			for (int i = 0; i < 5; i++)
 *				weights[i] = ((float) temp[i]) / 100;
 *	}
 *}
 */
	public void checkReally(String really, int temp[]) {
		if (really.equals("Y")) {
			for (int i = 0; i < 5; i++)
				weights[i] = ((float) temp[i]) / 100;
		}
	}

/**
 *TODO �qfile�����Z
 *getGrades(iD){
 *   return grades.get(iD);
 *}
 */
	public Grades getGrades(String iD) {
		return grades.get(iD);
	}

/**
 *TODO hashmap�����Z
 *HashMap<String, Grades> getGrades() {
 *		return grades;
 *}  
 */
	public HashMap<String, Grades> getGrades() {
		return grades;
	}

}
