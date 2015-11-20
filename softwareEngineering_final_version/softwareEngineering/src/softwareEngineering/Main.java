/** ##################################################################
實現所有Class
讓使用者(學生)取得他的總成績total grade 及排名 rank.(class GradeSystems)
Total grade 基於配分weights 來算 ， weights可以update. (class Grades,class GradeSystems)
Rank 表示此 total grade 在全班學生的分數排序(class GradeSystems)

Input file: 全班學生的分數(gradeinput)
形式順序:ID name lab1 lab2 lab3 midTerm finalExam
#################################################################### */

package softwareEngineering;

import java.io.FileNotFoundException;

public class Main extends Object {

		public static void main (String args[]) {
		  try { 
			  //call.IU() 建構 aUI
			  UI aUI = new UI();
			  aUI.start();
		} catch (NoSuchIDExceptions e1) {
			System.out.println("No such ID");
		} // ex ID錯了!
		catch (NoSuchCommandExceptions e2) {
			System.out.println("No such command");
		}// ex指令錯了!
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

