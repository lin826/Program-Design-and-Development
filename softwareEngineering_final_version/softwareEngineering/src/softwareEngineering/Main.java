/** ##################################################################
��{�Ҧ�Class
���ϥΪ�(�ǥ�)���o�L���`���Ztotal grade �αƦW rank.(class GradeSystems)
Total grade ���t��weights �Ӻ� �A weights�i�Hupdate. (class Grades,class GradeSystems)
Rank ��ܦ� total grade �b���Z�ǥͪ����ƱƧ�(class GradeSystems)

Input file: ���Z�ǥͪ�����(gradeinput)
�Φ�����:ID name lab1 lab2 lab3 midTerm finalExam
#################################################################### */

package softwareEngineering;

import java.io.FileNotFoundException;

public class Main extends Object {

		public static void main (String args[]) {
		  try { 
			  //call.IU() �غc aUI
			  UI aUI = new UI();
			  aUI.start();
		} catch (NoSuchIDExceptions e1) {
			System.out.println("No such ID");
		} // ex ID���F!
		catch (NoSuchCommandExceptions e2) {
			System.out.println("No such command");
		}// ex���O���F!
		catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		}
		
		public class NoSuchIDExceptions extends Exception {

		}
		public class NoSuchCommandExceptions extends Exception { 
		}


}

