/** ***********************************************************************
class UI (user interface) 

checkID(ID)
promptCommand(entered string)
promptID()
showFinishMsg()
showWelcomeMsg()
UI() �غc�l �غc aGradeSystem
start()
 ************************************************************************ */

package softwareEngineering;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;

import softwareEngineering.Main.NoSuchCommandExceptions;
import softwareEngineering.Main.NoSuchIDExceptions;

/**
 *TODO �ˬd�O�_����ID
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
 * TODO �ھکҿ�J���r�갵���P���ʧ@
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
 * TODO ��JQ�N���} ��J���T��ID�N�~��
 * promptID(){
 * ID = (scanner.next());
 * }
 */
	public void promptID() {
		System.out.print("��JID�� Q (�����ϥ�)�H");
		ID = (scanner.next());
	}

/**
 * TODO ��ܵ���
 * showFinishMsg()
 */
	public void showFinishMsg() {
		System.out.println("exit the system");
	}

/**
 * TODO ��ܶ}�l(�|��ܫ��O������)
 * showWelcomeMsg()	
 */
	public void showWelcomeMsg() {
		System.out.println("\nWelcome  "
				+ (gradeSystems.getGrades(ID)).getStudentName());
		System.out.println("enter the command");
		System.out.println("1) G ��ܦ��Z (Grade)");
		System.out.println("2) R ��ܱƦW (Rank)");
		System.out.println("3) W ��s�t�� (Weight)");
		System.out.println("4) E ���}��� (Exit)  ");
	}

/**
 * UI() �غc�l �غc aGradeSystem	
 */
	public UI() throws FileNotFoundException {

		gradeSystems = new GradeSystems();
		scanner = new Scanner(System.in);
	}

/**
 * 	
 *TODO ��{checkID,promptID
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
