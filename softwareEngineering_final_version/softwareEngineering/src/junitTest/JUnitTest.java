/** ----------------------------------------------------------------------------------------------------------------------
Unit test

before() system.out("Try")

after() system.out("End try")

case 1 : true ID
case 2 : false ID
testCheckID()

case 1: contain this ID
case 2: not contain this ID
testContainsID

case 1: lab1 0.1  lab2 0.1  lab3 0.1  midTerm 0.3  finalExam 0.4
case 2: lab1 0.2  lab2 0.2  lab3 0.2  midTerm 0.2  finalExam 0.2
testCalculateTotalGrade()
------------------------------------------------------------------------------------------------------------------------- */

package junitTest;

import java.util.HashMap;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import softwareEngineering.GradeSystems;
import softwareEngineering.Grades;
import softwareEngineering.Main.NoSuchCommandExceptions;
import softwareEngineering.Main.NoSuchIDExceptions;
import softwareEngineering.UI;

import java.io.FileNotFoundException;

public class JUnitTest {
	float[] weights = { (float) 0.1, (float) 0.1, (float) 0.1, (float) 0.3,
			(float) 0.4 };
	int[] weights2 = { 20, 20, 20, 20, 20 };
	String tempID = new String("955002056");
	String tempName = new String("³\¤åÄÉ");
	String[] testArray = { tempID, tempName, "88", "92", "88", "98", "91" };

	// HashMap<String, Grades> grades = new HashMap<String, Grades>();

	@Before
	public void before() {
		System.out.println("Try");
	}

	@After
	public void after() {
		System.out.println("End try");
	}
	
/**
 *case 1 : true ID
 *case 2 : false ID
 *testCheckID(){
 *	if(test.checkID(tempID))
 *	  System.out.println("true")
 *   else System.out.println("false")
 *   
 *   if(test.checkID(errorID))
 *	  System.out.println("true")
 *   else System.out.println("false")
 *}
 */
	@Test
	public void testCheckID() {
		try {
			UI test = new UI();
			System.out.println("it must return 'true'");
			if (test.checkID(tempID)) {
				System.out.println("true");
			} else
				System.out.println("false");
		} catch (FileNotFoundException e1) {
			System.out.println("file not found");
		}

		try {
			UI test = new UI();
			System.out.println("it must return 'false'");
			if (test.checkID("111111")) {
				System.out.println("true");
			} else
				System.out.println("false");
		} catch (FileNotFoundException e1) {
			System.out.println("file not found");
		}
	}

/**
 * case 1: contain this ID
 * case 2: not contain this ID
 * testContainsID{
 *	if(test.containsID(tempID))
 *	  System.out.println("contain");		
 *	else System.out.println("not contain");
 *	
 *	if(test.containsID(errorID))
 *	  System.out.println("contain");		
 *	else System.out.println("not contain");
 * }	
 */
	@Test
	public void testContainsID() {
		System.out.println("it must return 'contain'");
		try {
			GradeSystems test = new GradeSystems();
			if (test.containsID(tempID)) {
				System.out.println("contain");
			} else
				System.out.println("not contain");
		} catch (FileNotFoundException e1) {
			System.out.println("file not found");
		}

		System.out.println("it must return 'not contain'");
		try {
			GradeSystems test = new GradeSystems();
			if (test.containsID("11111")) {
				System.out.println("contain");
			} else
				System.out.println("not contain");
		} catch (FileNotFoundException e1) {
			System.out.println("file not found");
		}

	}

/**
 *case 1: lab1 0.1  lab2 0.1  lab3 0.1  midTerm 0.3  finalExam 0.4
 *case 2: lab1 0.2  lab2 0.2  lab3 0.2  midTerm 0.2  finalExam 0.2
 *testCalculateTotalGrade(){
 *   Grades case1 = new Grades(testArray);
 *	case1.calculateTotalGrade(weights);
 *	GradeSystems test2 = new GradeSystems();
 *	test2.showGrade(tempID);
 *	System.out.println("the total grade must be "+ (88 * 0.1 + 92 * 0.1 + 88 * 0.1 + 98 * 0.3 + 91 * 
 *0.4));
 *
 *GradeSystems case2= new GradeSystems();
 *	case2.checkReally("Y", weights2);
 *	case2.showGrade(tempID);
 *	System.out.println("the total grade must be "+ (88 * 0.2 + 92 * 0.2 + 88 * 0.2 + 98 * 0.2 + 91 * 0.2));
 *    
 *}
 */
	@Test
	public void testCalculateTotalGrade() {
		Grades test = new Grades(testArray);
		test.calculateTotalGrade(weights);
		try {
			GradeSystems test2 = new GradeSystems();
			test2.showGrade(tempID);
			System.out.println("the total grade must be "
					+ (88 * 0.1 + 92 * 0.1 + 88 * 0.1 + 98 * 0.3 + 91 * 0.4));
		} catch (FileNotFoundException e1) {
			System.out.println("file not found");
		}

		try {
			GradeSystems test3 = new GradeSystems();
			test3.checkReally("Y", weights2);
			test3.showGrade(tempID);
			System.out.println("the total grade must be "
					+ (88 * 0.2 + 92 * 0.2 + 88 * 0.2 + 98 * 0.2 + 91 * 0.2));
		} catch (FileNotFoundException e1) {
			System.out.println("file not found");
		}
	}

}
