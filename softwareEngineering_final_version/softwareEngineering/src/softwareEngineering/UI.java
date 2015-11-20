/** ***********************************************************************
class UI (user interface) 

checkID(ID)
promptCommand(entered string)
promptID()
showFinishMsg()
showWelcomeMsg()
UI() 建構子 建構 aGradeSystem
start()
 ************************************************************************ */

package softwareEngineering;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;

import softwareEngineering.Main.NoSuchCommandExceptions;
import softwareEngineering.Main.NoSuchIDExceptions;

/**
 *TODO 檢查是否有此ID
 *checkID(ID){
 *	if (gradeSystems.containsID(ID)) return true;
 *	else return false;
 *}
 */
public class UI {
	private GradeSystems gradeSystems;
	private String ID;
	private Scanner scanner;

	public boolean checkID(String ID) {
		try {
			if (gradeSystems.containsID(ID))
				return true;
			else
				return false;
		} catch (NullPointerException e) {
			// e.printStackTrace();
			throw e;
		}
	}

/**
 * 
 * TODO 根據所輸入的字串做不同的動作
 * promptCommand(entered string){
 * switch (entered string) {
 *	case "G":
 *		gradeSystems.showGrade(ID);
 *		break;
 *	case "R":
 *		gradeSystems.showRank(ID);
 *		break;
 *	case "W":
 *		gradeSystems.updateWeights();
 *		break;
 *	case "E":
 *		break;
 *}

*/
	public void promptCommand(String enter2) throws NoSuchCommandExceptions {
		switch (enter2) {
		case "G":
			gradeSystems.showGrade(ID);
			break;
		case "R":
			gradeSystems.showRank(ID);
			break;
		case "W":
			gradeSystems.updateWeights();
			break;
		case "E":
			// showFinishMsg();
			break;
		default:
			System.out.println("No such command");
			break;
		}
	}
/**
 * TODO 輸入Q就離開 輸入正確的ID就繼續
 * promptID(){
 * ID = (scanner.next());
 * }
 */
	public void promptID() {
		System.out.print("輸入ID或 Q (結束使用)？");
		ID = (scanner.next());
	}

/**
 * TODO 顯示結束
 * showFinishMsg()
 */
	public void showFinishMsg() {
		System.out.println("exit the system");
	}

/**
 * TODO 顯示開始(會顯示指令有哪些)
 * showWelcomeMsg()	
 */
	public void showWelcomeMsg() {
		System.out.println("\nWelcome  "
				+ (gradeSystems.getGrades(ID)).getStudentName());
		System.out.println("enter the command");
		System.out.println("1) G 顯示成績 (Grade)");
		System.out.println("2) R 顯示排名 (Rank)");
		System.out.println("3) W 更新配分 (Weight)");
		System.out.println("4) E 離開選單 (Exit)  ");
	}

/**
 * UI() 建構子 建構 aGradeSystem	
 */
	public UI() throws FileNotFoundException {

		gradeSystems = new GradeSystems();
		scanner = new Scanner(System.in);
	}

/**
 * 	
 *TODO 實現checkID,promptID
 *start(){
 *   		if (checkID(ID)) {
 *				command = scanner.next();
 *				while (!command.equals("E")) {
 *					promptCommand(command);
 *					if (command.equals("E")) break;
 *					command = scanner.next();
 *				}
 *				promptID();
 *		} 
 *		else {
 *				System.out.println("No such ID");
 *				promptID();
 *		}
 *} 
 */
	public void start() throws NoSuchIDExceptions, NoSuchCommandExceptions {

		String command;

		promptID();
		while (!ID.equals("Q")) {
			if (checkID(ID)) {
				showWelcomeMsg();
				command = scanner.next();
				while (!command.equals("E")) {
					promptCommand(command);
					if (command.equals("E"))
						break;
					showWelcomeMsg();
					command = scanner.next();
				}

				promptID();
			} else {
				System.out.println("No such ID");
				promptID();
			}
		}
		showFinishMsg();

	}
}
