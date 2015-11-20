/** *************************************************************************
class GradeSystems用HashmMap存儲student grades.

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
	// (初始值 lab1 0.1, lab2 0.1, lab3 0.1, midTerm 0.3, finalExam 0.4)
	// (注意weights 之和須等於1.0)
	private static Scanner input, scanner;
	private static String[] strItems = new String[5];
	{
		strItems[0] = "lab1：               ";
		strItems[1] = "lab2：               ";
		strItems[2] = "lab3：               ";
		strItems[3] = "mid-term：     ";
		strItems[4] = "final exam：";
	}

/**
 *TODO 看aGradeSystem有否含此ID
 *containsID(ID){
 *return containKey(ID)
 *}
 */
	// 儲存 a list of student grades.
	public boolean containsID(String ID) {
		// 看aGradeSystem有否含此ID
		return getGrades().containsKey(ID);
	}

/**
 * TODO 建構子
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
 * TODO 顯示成績 呼叫Grades的計算總成績
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
		System.out.println(thisStudent.getStudentName() + "'s grades：");
		for (int i = 0; i < 5; i++)
			System.out.println(strItems[i] + thisStudent.getScores()[i]);

		float totalGrades = thisStudent.calculateTotalGrade(weights);
		System.out.println("total grade：" + totalGrades);
	}

/**
 * TODO 顯示排名
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
		System.out.println(getGrades().get(ID).getStudentName() + "排名第" + rank);
	}

/**
 * TODO 重新輸入配分、 確認輸入新配=>呼叫check really
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
 *TODO 確認輸入的是否是Y 是的話就把新的配分更新
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
 *TODO 從file拿成績
 *getGrades(iD){
 *   return grades.get(iD);
 *}
 */
	public Grades getGrades(String iD) {
		return grades.get(iD);
	}

/**
 *TODO hashmap拿成績
 *HashMap<String, Grades> getGrades() {
 *		return grades;
 *}  
 */
	public HashMap<String, Grades> getGrades() {
		return grades;
	}

}
