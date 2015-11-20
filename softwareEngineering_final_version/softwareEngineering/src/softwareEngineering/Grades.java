/** *************************************************************************
class Grade �Ψӫغc�ǥͦW�٤έp��̫��`���Z


calculateTotalGrade(float[] weights)
getStudentName() 
getScores()
 *************************************************************************** */
package softwareEngineering;

import java.math.BigDecimal;

public class Grades {
	private String studentName;
	private int[] scores = new int[5];
//	int lab1		;
//	int lab2		;
//	int lab3		;
//	int mid_term	;
//	int final_exam;

/**
 * TODO �p��̫��`���Z(�|�ˤ��J)
 * calculateTotalGrade(float[] weights){
 *   for(i=0;i<5;i++)
 *   totalGrades += weights[i] * grade[i];
 *   return totalGrades;
 * }	
 */
	public float calculateTotalGrade(float[] weights){
		float totalGrades = 0;
		for(int i=0;i<5;i++)
			totalGrades += weights[i]*scores[i];
		float totalGrade = new BigDecimal(totalGrades)
        .setScale(1, BigDecimal.ROUND_HALF_UP)
        .floatValue();
		return totalGrade;
	}

	public Grades (String[] temp) {
		studentName = (temp[1]);
		for(int i=0;i<5;i++)
			scores[i] = Integer.parseInt(temp[i+2]);
	} //�غc�l

/**
 *TODO ���ǥͪ��W��
 *getStudentName() {
 *		return studentName;
 *}
 */	
	public String getStudentName() {
		return studentName;
	}
	
/**
 * TODO �����Z(��Ưx�})
 * getScores(){
 *		return scores;
 * }
 */
	public int[] getScores() {
		return scores;
	}

}
