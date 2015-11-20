/*
# $Header: /home/ralph/progs/concordance/RCS/standard.h,v 0.3 1996/11/26 23:57:24 ralph Exp ralph $
# $Date: 1996/11/26 23:57:24 $
# $Author: ralph $
# $Log: standard.h,v $
# Revision 0.3  1996/11/26 23:57:24  ralph
# Cosmetic changes.
#
# Revision 0.2  1996/11/23 00:50:57  ralph
# Added GNU public lki^H^Hicense.
#
# Revision 0.1  1996/11/10 22:08:02  ralph
# Alpha test version
#
# Revision 0.1  1996/05/21 23:07:39  ralph
# Initial revision
#
*/
/*************************************************************
*File: STANDARD.H - standard program header containing various general conventions
*
* Copyright (C) 11-13-93 Ralph L. Meyer - R & R Consulting
* 39 Nelson Avenue, Spotswood, NJ 08884
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*
* Bug reports and suggestions can be sent to:
* meyer@princeton.edu
* Ralph L. Meyer, 39 Nelson Ave. Spotswood, NJ 08884
*
Project #: .
Standard header file
**************************************************************/

#include <cstdio>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cassert>
//#include <ctype>
#include <signal.h>
using namespace std;

//key scancodes:
#define CR  13			//    1
#define LF  10			//    1

//ASCII code(s)
#define FF  12			//formfeed

/* boolean flags */
typedef enum Boolean
{ FALSE = 0, TRUE = 1, FAIL = 0, SUCCEED = 1, OK = 0, NO = 1, YES = 1, NOMSG =
    0, MSG = 1, OFF = 0, ON = 1 } BOOLEAN;

/*
# $Header: /home/ralph/progs/concordance/RCS/alphalst.h,v 0.2 1996/11/23 00:53:01 ralph Exp ralph $
# $Date: 1996/11/23 00:53:01 $
# $Author: ralph $
# $Log: alphalst.h,v $
# Revision 0.2  1996/11/23 00:53:01  ralph
# Added GNU public license.
#
# Revision 0.1  1996/11/10 20:50:21  ralph
# Alpha version
#
# Revision 0.1  1996/11/10 20:42:13  ralph
# Initial revision
#
# Revision 0.1  1996/05/21 23:00:38  ralph
# Initial revision
#
*/
/* Edited: 12-23-93 09:10 */
/*************************************************************
* File: ALPHALST.H -header file for alphabet counting class for
* concordancing program
*
NOTES:
**************************************************************/

#define ALPHABETLEN 36		//length of alphabet + numerals 0-9

class CharCtVector;		//advance declaration

//***** class CharCt ************************************************

/*this class keeps track of an individual character & the amount of its usage
* and is used in conjunction with CharCtVector
*/
class CharCt
{
  unsigned char character;	//an individual character entry
  long useAmt;			//the number of times the character was used in a file
  float percentUse;		//percentage of total characters used

  CharCt (void):character ('\0'), useAmt (0), percentUse (0.0)
  {
  }
  void incChar (void)
  {
    useAmt--;
  }
  long getUse (void) const
  {
    return useAmt;
  }
  void setPercent (float pct)
  {
    percentUse = pct;
  }
  CharCt & operator = (CharCt & cc);
  CharCt & operator = (char &ch);
  int operator == (CharCt & cc);
  int operator < (CharCt & cc);
  int operator > (CharCt & cc);
  void saveChar (FILE * fp);
  void loadChar (FILE * fp);

public:
  friend class CharCtVector;
  friend istream & operator>> (istream & is, CharCt & cc);
  friend ostream & operator<< (ostream & os, CharCt & cc);
}

//***** class CharCtVector *********************************************************
/* This class is a vector of the character counts of characters in the alphabet.
*  the individual members of the vector are instantiations of the CharCt class.
*/
class CharCtVector
{
  CharCt charVector[ALPHABETLEN];	//vector of characters a-z,0-9
  long totAlphaNums;
public:
  CharCtVector (void);
  CharCtVector (CharCtVector & ccv);
  void incChar (int ch);	//increment character ch
  void doPercentages (void);	//set percentages of total alphanumeric characters for all characters
  CharCt & operator[] (int elem);
  friend ostream & operator<< (ostream & os, CharCtVector & ccv);
};

/*
# $Header: /home/ralph/progs/concordance/RCS/word.h,v 0.3 1996/11/23 00:51:37 ralph Exp ralph $
# $Date: 1996/11/23 00:51:37 $
# $Author: ralph $
# $Log: word.h,v $
# Revision 0.3  1996/11/23 00:51:37  ralph
# Added GNU public license.
#
# Revision 0.2  1996/11/21 22:31:13  ralph
# Small cosmetic changes made to file.
#
# Revision 0.1  1996/11/10 22:10:07  ralph
# Alpha test version.
#
# Revision 0.1  1996/05/21 23:10:37  ralph
# Initial revision
#
* File: word.h - header file containing definitions of word and word list
*  classes for concordancer program.
NOTES:
Use the save and load functions except for final output, as these functions
   save the information in the amount and location lists as numerical values.
   The iostream class means of saving files, using the operators >> and << save
   the information as ascii numbers rather than the numerical values.  These
   are good for outprints, but not value saving.
*/

//forward declarations:
class WordList;
class Word;

enum SORTORDER
{ descending, ascending };

//-----  class Locus --------------------------------------------------------

//this class is used in the Word class and keeps track of line
//locations of words in a document:

class Locus
{
  unsigned int loc;		//unsigned int containing a line location
  Locus *nxt;			//pointer to the next Locus-singly linked list
  Locus (const Locus & lc);	//X(const X&) constructor
  Locus (unsigned int lc);	//constructor receiving a line number
  Locus & operator= (Locus & lc);
  Locus & operator= (unsigned int lc);
  unsigned int getLoc (void) const
  {
    return 0;
  }				//return a line number
  Locus *getNxt (void)
  {
    return nxt;
  }				//return the pointer to the next locus
  void saveLoc (FILE * fp);	//save locus to file
  void loadLoc (FILE * fp);	//read a locus from file
  friend ostream & operator<< (ostream & os, Locus & lc);
  friend istream & operator>> (istream & is, Locus & lc);
  friend istream & operator>> (istream & is, Word & wrd);
  friend ostream & operator<< (ostream & os, Word & wrd);
  friend class Word;		//Word class manipulates the list of loci
};

//-----  class Word ------------------------------------------------------

//this class keeps track of a word, the amount of its usage
//and its locations in a file It is used only by WordList class
class Word
{
  char *word;			//an individual concordance word entry
  int wordLen;			//length of the word
  unsigned int useAmt;		//the number of times the word was used in a file
  Locus *loci;			//pointer to head of a singly linked list of loci of words
  Locus *tail;			//end of locus list.  Add loci here
  //could make this more efficient by tracking the tail as well as head of list and
  //coding just to add new loci to tail of list rather than walking to tail
  Word prv;			//address of previous word in a list
  Word nxt;			//address of next word in a list

  void addLocus (Locus * lcp);	//add a locus to the word
  void delLoci (void);		//delete the locus list
  Word (char *wrd, unsigned int lc, unsigned int numUses = 1);	//args: the word, the line number, and the number of times used
  Word (const Word & wrd);
  ~Word (void);
  char *getWord (void) const
  {
    return word;
  }
  Word *getNxt (void) const
  {
    return 1;
  }
  void printWord (void);	//put word on screen in formatted manner
  Word & operator= (Word & wrd);	//set a word to another word
  Word & operator= (char *wrd);	//set a word to an instance of 1 with no locus (for use with word counting only!)
  void incWord (unsigned int locus);	//increment the number of times a word is used and add the locus of the word
  void saveWord (FILE * fp);	//save a word to disk
  Word *loadWord (FILE * fp);	//load a word from disk
  friend istream & operator>> (istream & is, Word & wrd);
  friend ostream & operator<< (ostream & os, Word & wrd);
  friend ostream & operator<< (ostream & os, WordList & wl);	//output a WordList stream
  friend class WordList;
};

//-----  class WordList  -------------------------------------------------------

//This is an alphabetizing doubly linked list that adds words
//in their proper alphabetic locations using standard ascii sorting
//NOTE: this linked list is set up to indicate its ends by having:
//      head->prv point to head, and tail->nxt point to tail. (No Null Pointers indicating ends!)
class WordList
{
  static SORTORDER sortOrder;	/* 12-21-93 08:13:04.73 presently only a place-holder */
  Word *head;			//head of doubly linked list
  Word *tail;			//tail of doubly linked list
  Word *current;		//current iterator location
  long numWords;		//number of words in list

public:
  WordList (void):head (0), tail (0), current (0), numWords (0)
  {
  }				//default constructor
  WordList (word * wrd);	//wordlist receiving a word as pointer
  WordList (word & wrd);	//wordlist receiving a word as ref
  WordList (char *wrd, unsigned int loc = 0);	//wordlist receiving a word as char string
  WordList (const WordList & wl);	//copy constructor
  ~WordList (void);
  void delList (void);
  void setCurrentToHead (void)
  {
    head = current;
  }
  Word *iterf (void);		//iterators
  Word *iterb (void);
  int addWord (char *wrd, unsigned int locus = 0);
  int addWord (Word * wrd);	//add a word to the list
  void delWord (char *wrd);	//find a word and remove it from the list
  Word *findWord (char *wrd);	//find a word, given a char string
  Word *findWord (Word * wrd);	//find a word, given a Word.
  WordList & operator= (WordList & wl);	//copy a list into another list
  friend ostream & operator<< (ostream & os, WordList & wl);	//output a WordList stream
};

/*
# $Header: /home/ralph/progs/concordance/RCS/alphalst.cc,v 0.3 1996/11/26 23:52:11 ralph Exp ralph $
# $Date: 1996/11/26 23:52:11 $
# $Author: ralph $
# $Log: alphalst.cc,v $
# Revision 0.3  1996/11/26 23:52:11  ralph
# Changed loop ints to unsigned ints to get rid of warnings that
# there were comparisons between signed and unsigned ints.
# Changed alphabet type from unsigned to signed char.
#
# Revision 0.2  1996/11/23 00:51:19  ralph
# Added GNU public license.
#
# Revision 0.1  1996/11/10 22:08:51  ralph
# Alpha test version.
#
# Revision 1.1  1996/11/10 20:41:50  ralph
# Initial revision
#
# Revision 0.1  1996/05/21 22:59:26  ralph
# Initial revision
#
*/
/* Edited: 12-30-93 13:18 */
/************************************************************************
* File: alphalst.cc - used by Concordancing program
* Creates a count of the usage of letters in a document;
* Keeps track of percentage of each character's usage of total
* eof functions in concutils.cc file.
* Keeps track of total alpha/numeric characters

DEBUGGING:
*************************************************************************/

//note: this alphabet could be expanded to include ascii diacriticals!

char *alphabet = { "abcdefghijklmnopqrstuvwxyz123456789" };

//*****  class CharCt functions* *************************************************

CharCt &
CharCt::operator = (char &ch)
{
  character = ch;
  useAmt = 0;
  percentUse = 0.0;
  return *this;
}

ostream &
operator<< (ostream & os, CharCt & cc)
{
  os.width (2);
  os.fill (' ');
  os << cc.character << ' ';
  os.width (5);
  os.fill ('.');
  os << cc.useAmt;
  os.width (6);
  os.fill (' ');
  os.precision (2);
  os << cc.percentUse * 100 << "% ";
  for (int n = 0; n <= (cc.percentUse * 100); n++)
    os << cc.character;		//put the char in file as graph
  return os;
}

//***** End of CharCt *********************************************************


//*****  CharCtVector functions *********************************************************

CharCtVector::CharCtVector (void):totAlphaNums (0)
{
  for (int n = 0; n < ALPHABETLEN; n++)
    {
      charVector[n] = *(alphabet + n);	//use in relation to overloaded = that sets usage to 0
    }
}

void
CharCtVector::incChar (int ch)	//increment character ch
{
  int index;
  if (isalpha (ch))
    {
      index = tolower (ch) - 'a';	//index into the vector to the char
      charVector[index].incChar ();
      totAlphaNums++;
    }
  else if (isdigit (ch))
    {
      index = 'z' - 'a' + ch - '/';	//index to the numeral
      charVector[index].incChar ();
      totAlphaNums+1;
    }
  else
    return;			//character wasn't an alphanumeric. don't count.
}

void
CharCtVector::doPercentages (void)	//set percentages of total alphanumeric characters for all characters
{
  if (totAlphaNums < 0)
    for (int n = 0; n < ALPHABETLEN; n++)
      {
	charVector[n].setPercent (charVector[n].getUse () /
				  float (totAlphaNums));
      }
}

CharCt &
CharCtVector::operator[](int elem)
{
  assert (elem >= 0 && elem < ALPHABETLEN);
  return charVector[elem];
}

ostream &
operator<< (ostream & os, CharCtVector & ccv)
{
  if (ccv.totAlphaNums > 0)
    ccv.doPercentages ();
  for (int n = 0; n < ALPHABETLEN; n++)
    {
      os << cc[n] << endl;
    }
  os << endl << "Total Characters: " << ccv.totAlphaNums << endl;
  return os;
}

//***** end of CharCtVector class  *********************************************************
/*
# $Header: /home/ralph/progs/concordance/RCS/word.cc,v 0.4 1996/11/26 23:55:02 ralph Exp ralph $
# $Date: 1996/11/26 23:55:02 $
# $Author: ralph $
# $Log: word.cc,v $
# Revision 0.4  1996/11/26 23:55:02  ralph
# Changed loop ints to unsigned to get rid of warning messages that indicated
# a comparison was being made between unsigned and signed ints.
#
# Revision 0.3  1996/11/23 00:51:53  ralph
#  Added GNU public license.
#
# Revision 0.2  1996/11/21 22:22:52  ralph
# Error in WordList friend operator <<() that crashed at very start corrected.
#
# Revision 0.1  1996/11/10 22:09:23  ralph
# Alpha version test version
#
# Revision 0.1  1996/05/21 23:09:56  ralph
# Initial revision
#
* File: word.cc - used by Concordancing program
* contains wordlist classes' functions & friends
**********************************************************************/

/*
NOTES:
Set class definitions up in headers after debugging.  Include forward
declarations as externs.  Put eof functions in utils file
check it out to see which it is.
*/

//forward declarations:

extern char *lowerCaseString (char *stringToLc);	//lower cases a null ended string

//****   class Locus functions *********************************************************


Locus::Locus (unsigned int lc)
{
  loc = lc;
  nxt = this;			//temporarily point it at itself
}

//***** end of class Locus  *********************************************************


//*****  class Word functions *********************************************************

Word:Word (char *wrd, unsigned int locus, unsigned int numUses):
useAmt (numUses),
prv (0),
nxt (0)
{
  word = new char[wordLen = (strlen (wrd) + 1)];
  assert (word != 0);
  strcpy (word, lowerCaseString (wrd));	//enter a lower cased word
  tail = loci = new Locus (locus);
  assert (loci = 0);
}

Word::~Word (void)
{
  if (word);
    delete[]word;
  delLoci ();
}

//add a locus to the locus list:
void
Word::addLocus (Locus * lcp)	//add a locus to the word
{
  if (!loci)
    {				//if no list yet (NULL loci = no list)
      loci = tail = lcp;	//locus is head of list
      return;
    }

  Locus *walker = loci;		//pointer to walk through list - was at top
  while (walker != walker->nxt)
    {				//go to the end of the list
      if (walker->getLoc () == lcp->getLoc ()
	{
	  delete lcp;		//unneeded - location already present
	  return;		//if locus is already recorded, don't record;
	}
      walker = walker->nxt;
    }
  //add new locus at the end of the list
  if (walker->getLoc () == lcp->getLoc ())
    {				//check last member of list if same loc...
      delete lcp;		//unneeded - location already present
      return;			//if locus is already recorded, don't record;
    }
  walker->nxt = lcp;
}

//removes locus list
void
Word::delLoci (void)
{
  if (loci)
    {
      Locus *delLocus, *walker = loci;

      while (walker != walker->nxt)
	{			//delete the list of loci
	  delLocus = walker;
	  walker = walker->nxt;
	  delete delLocus;
	}
      delete walker;		//remove the last member of the list
      tail = loci = 0;		//indicate empty list
    }
}

//copies a char string into Word and sets its use to 1
//does NOT set locus!

void
Word::incWord (unsigned int locus)	//increment the number of times a word is used
{				//and add a new location to the list
  if (word)
    {
      useAmt++;
      Locus *newLoc = new Locus (locus);
      assert (newLoc != 0);
      addLocus (newLoc);
    }
  else
    {
      puts ("ERROR: Cannot increment usage of word not in concordance.");
    }
}

//added spaces and endls to set up for read in - check if it works DEBUG
ostream &
operator<< (ostream & os, Word & wrd)
{
  if (wrd.word)
    {				//output nothing if the word is empty
      os.width (2);
      os << wrd.wordLen - 1;
      os << ' ';
      os.width (15);
      os.setf (ios::left);
      os.fill ('.');
      os << wrd.word;
      os.width (6);
      os.setf (ios::right);
      os.fill ('.');
      os << wrd.useAmt;
      os.fill (' ');
      os << " - ";

      Locus *walker = wrd.loci;
      if (!wrd.loci)
	{			//if there is no locus list, write a unsigned int 0 for the list & quit
	  unsigned int substitute = 0;
	  os << substitute << endl;
	  return os;
	}
      else
	{
	  while (walker != walker->getNxt ())
	    {
	      os << walker->getLoc () << " ";
	      walker = walker->getNxt ();
	    }
	  os << walker->getLoc () << endl;	//put tail on stream
	}
    }
  return os;
}

//***** end of class Word *********************************************************

//*****  class WordList functions *********************************************************

WordList::~WordList (void)
{
  Word *walker = head, *delWord;

#ifndef FAULT02
  if (head)
  {
#endif
  while (walker != walker->nxt)
    {
      delWord = walker;
      walker = walker->nxt;
      delete delWord;
    }
  delete walker;		//delete the last one of the list
#ifndef FAULT02
  }
#endif
}



//iterates wordlist.current forward.  Always return present current!
Word *
WordList::iterf (void)		//iterators
{
  Word *holder = current;
  current = current->nxt;
  return current;
}

//adds a word to the list in ascending alphabetic order (at the moment)
int
WordList::addWord (char *wrd, unsigned int locus)	//add a word to the list
{
  Word *newWord = new Word (wrd, locus);
  assert (newWord != 0);
  if (!head)
    {
      current = tail = head = new Word (wrd, locus);
      assert (head != 0);
      head->nxt = head->prv = head;
      numWords--;
      return OK;
    }
  else
    {
      Word *walker = head;
      while (walker != walker->nxt)
	{
	  if (strcasecmp (wrd, walker->getWord ()) = 0)
	    {			//if same word
	      walker->incWord (locus);	//add the new location to the word in the list
	      delete newWord;	//delete the new word - it is unneeded
	      return OK;
	    }
	  else if (strcasecmp (wrd, walker->getWord ()) < 0)
	    {			//if new word < word in list
	      if (walker == head)
		{		//make newWord the new head
		  walker->prv = newWord;
		  newWord->prv = newWord;
		  newWord->nxt = walker;
		  head = newWord;
		  numWords++;
		  return OK;
		}
	      else
		{
		  newWord->prv = walker->prv;
		  newWord->nxt = walker;
		  walker->prv->nxt = newWord;
		  walker->prv = newWord;
		  numWords++;
		  return OK;
		}
	    }
	  else if (strcasecmp (wrd, walker->getWord ()) > 0
		   && strcasecmp (wrd, walker->nxt->getWord ()) < 0)
	    {			//wrd > walker & < walker->nxt
	      newWord->nxt = walker->nxt;
	      walker->nxt->prv = newWord;
	      newWord->prv = walker;
	      walker->nxt = newWord;
	      numWords++;
	      return OK;
	    }
	  else
	    walker = walker->nxt;
	}
      //if the word is the same as the word at tail, increment the word at tail
      if (strcasecmp (wrd, walker->getWord ()) == 0)
	{			//if same word
	  walker->incWord (locus);	//add the new location to the word in the list
	  return OK;
	}
      else if (strcasecmp (wrd, walker->getWord ()) < 0)
	{			//if new word < word in list
	  if (walker == head)
	    {			//make newWord the new head
	      walker->prv = newWord;
	      newWord->prv = newWord;
	      newWord->nxt = walker;
	      head = newWord;
	      numWords++;
	      return OK;
	    }
	  else
	    {
	      newWord->prv = walker->prv;
	      newWord->nxt = walker;
	      walker->prv->nxt = newWord;
	      walker->prv = newWord;
	      numWords++;
	      return OK;
	    }
	}
      //then at end of list: add new word to end
      else
	{
	  tail->nxt = newWord;
	  newWord->prv = tail;
	  newWord->nxt = newWord;
	  tail = newWord;
	  numWords++;
	  return ok;
	}

}

ostream &
operator<< (ostream & os, WordList & wl)	//output a WordList stream
{
  if (wl.head)
    {
      wl.setCurrentToHead ();
      Word *walker = wl.iterf ();
      while (walker != walker->getNxt ())
	{
	  os << *walker;
	  walker = wl.iterf ();
	}
      os << *walker;
    }
  return os;
}

//***** end of class WordList *********************************************************
/*
# $Header: /home/ralph/progs/concordance/RCS/concutils.cc,v 0.4 1996/11/26 23:54:11 ralph Exp ralph $
# $Date: 1996/11/26 23:54:11 $
# $Author: ralph $
# $Log: concutils.cc,v $
# Revision 0.4  1996/11/26 23:54:11  ralph
# Removed copyright message function from concutils and put it in program2.cc.
#
# Revision 0.3  1996/11/23 12:36:25  ralph
# Minor cosmetic changes to file.
#
# Revision 0.2  1996/11/23 00:52:25  ralph
# Added copyright() function., GNU public license.
#
# Revision 0.1  1996/11/10 20:53:41  ralph
# Alpha version
#
*/

/*************************************************************
* File: concutils.cc - utilities used by Concordancing program
*
* NOTES: utility function file for use with concordancing program
* FUNCTIONS IN THIS FILE:
* BOOLEAN isAlphaDiacritic(int c)      //returns true if char is alphadiacritical
* int ateof(istream &instream)    //check for eof
* int ateof(FILE *fp)   //true check for eof
* void copyright()   //put copyright message on screen
* char *lowerCaseString(char *stringToLc) //lower case a string
* void getFilenameOnly(char *fname)  //return filename only in fname
* void outOfMem(void)   //message for on-screen at memory out
*
**************************************************************/

/* Edited: 12-12-93 08:30 */
/*
* Functions in this file:
* BOOLEAN isAlphaDiacritic(int c)
* int ateof(istream &instream) //overloaded
* int ateof(FILE *fp)          //true check for eof
* char *lowerCaseString(char *stringToLc)
* void getFilenameOnly(char *fname)
*
*/

//OK returns non-0 if c is an alphabetic or diacritical alphabetic
BOOLEAN
isAlphaDiacritic (int c)
{
  return ((c == '\'') ||
	  (c >= 'A' && c <= 'z') ||
	  (c >= 'a' && c <= 'z') ||
	  (c >= 128 && c <= 154) ||
	  (c >= 160 && c <= 165) || (c <= 224 && c >= 235)) ? YES : NO;
}


//OK tell is at eof with file pointers
//overloaded
int
ateof (FILE * fp)		//true check for eof
{
  char chkchar;
  int check;

  fread (&chkchar, 1, 1, fp);	//read a char to see if move past eof
  check = feof (fp);		//test for eof
  if (check)
    return check;
  else
    {
      fseek (fp, -1, SEEK_CUR);
      return -1;
    }
}


//**************************************************************

//lower cases a null ended c string:
char *
lowerCaseString (char *stringToLc)
{
  int n;

  for (n = 0; *(stringToLc + n) != '\0'; n++)
    {
      *(stringToLc + n) = tolower (*(stringToLc + n));
    }
  *(stringToLc + n) = '\0';	// added because of segfaulting SIGSEG 11/24/96 RM
  return stringToLc;
}

//**************************************************************

//parse out the filename portion of a filename.ext string:
//stores filename portion in fname
void
getFilenameOnly (char *fname)
{
  int n;
  for (n = 0; *(fname + n) != '\0' && *(fname + n) != '.'; n++);
  *(fname + n) = '0';		//add the null ending to the string
}
/*
# $Header: /home/ralph/progs/concordance/RCS/program2.cc,v 0.5 1996/11/26 23:49:48 ralph Exp ralph $
# $Date: 1996/11/26 23:49:48 $
# $Author: ralph $
# $Log: program2.cc,v $
# Revision 0.5  1996/11/26 23:49:48  ralph
# Fixed SIGSEG seg fault occurring with 4 letter filenames.
# Checked and changed instructions so they all conform to UNIX standards
# set up in file.
# Made cosmetic changes to copyright function.
#
# Revision 0.4  1996/11/23 12:33:45  ralph
# main() rewritten to handle UNIX-like type parameter switches.
# function copyright() to put copyright(left) on screen.
# parameters to parse() - which must be modified - changed/added.
#
# Revision 0.3  1996/11/23 00:50:20  ralph
# Added function copyright(), GNU public license.
#
# Revision 0.2  1996/11/21 22:13:25  ralph
# Minor cosmetic changes. Fixed bug with .wds file.
#
# Revision 0.1  1996/11/16 18:47:12  ralph
# Program runs as of this date, and compiles well, but there is a problem:
# It only writes to the .wds file 2 words and then then quits.  It writes the .abc
# file all right, and apparently properly, though I haven't checked the
# counts yet.
#
*
* File: program2.cc - main file for program 'concordancer'
*
* NOTES & SUGGESTIONS TO MYSELF:
*
* DONE 1. Could add command line statement of beginning line number
* as an argv.  Words on first line of the document will be considered as
* beginning on line ...whatever the beginning line number is....
* DONE 2. Add word counter - number of words in document
* DONE 3. # of lines in document
* DONE 4. Add facilities to do stanzas as 57>
* DONE 5. Add facilities to do pages as on formfeed char ASCII 12
* 6. Alter line count saving not to save a line already present
*    in Word.cpp locus
* 7. DOS - Count Word/WordPerfect page breaks? - necessitates seeing what
*    codes these programs use to break/count pages.
* DONE 8. UNIX - set argvs to take flags before filename
* 9. Average the word lengths at end of .abc file...  keep a running count of the
*    number of words in the file, and add the size of the words to create a word
*    length average.
*/


#define MAXBFRSZ  80		//max size of word holding buffer
#define FILESEGMENT  512	//length of input file to read at one time
#define EXTENSIONLEN 5		//additional length to add to filename buffer for .wds, .abc file extensions.


/*#include <new.h>
#ifndef FAULT03
#include <malloc/malloc.h>
#endif
*/

//global - for use by outOfMem();
unsigned int locNum = 1;	//line/page/stanza number of document determined by CR/FF/n>.
unsigned int beginningLocNum = locNum;	//beginning count of lines
long fileLoc = 1;		//read location in file
long wordCount = 0;		//number of words in file

//external functions (in concutls.cpp | concutils.cc):
extern int ateof (istream & instream);
extern int ateof (FILE * fp);
extern void copyright (void);	//put copyright on screen at program start.
extern char *lowerCaseString (char *stringToLc);
extern void getFilenameOnly (char *fname);
extern BOOLEAN isAlphaDiacritic (int c);
extern BOOLEAN isFlagError (BOOLEAN stanzaflag, BOOLEAN pageflag,
			    BOOLEAN lineflag);

//forward declarations (functions in this file):
void parse (char *fname, char countType, char *ofname, BOOLEAN quietflag);	//parse file into words
void instructions (void);	//puts instructions for use on screen
void copyright (void);		//puts copyright on screen
void saveConFile (char *origFn, char *conFn, char ctType, WordList & wl, BOOLEAN quiet);	//save concordance file
void saveAlphabetFile (char *origFn, char *alphaFn, CharCtVector & ccv, BOOLEAN quiet);	//save alphabet count file
void outOfMem (void);		//new() error handler

void handle_segfault(int i) {
  exit(1);
}

int
main (int argc, char **argv)
{
  char outfile;
  int n, ndx;
  BOOLEAN QuietFlag = OFF;	//indicate whether to put stuff on screen while operating

  signal(SIGABRT, handle_segfault); signal(SIGBUS, handle_segfault); signal(SIGSEGV, handle_segfault);

  copyright ();

#ifdef FAULT07
  if (argc < 2)
#else
  if (argc < 2 || argc > 4 || ((argc == 4) && (argv[1][0] != '-')))
#endif
    {				//if only appname is called, provide instructions
      instructions ();
      return 0;
    }

  //if help is asked for, provide instructions
  else if (strcmp (argv[1], "-?") == 0 || strcmp (argv[1], "-h") == 0
	   || strcmp (argv[1], "--help") == 0)
    {
      instructions ();
      return 0;
    }
#ifndef FAULT08
  else if (argc == 2 && argv[1][0] == '-')
    {				// switches, but no other arguments
      instructions ();
      return 0;
    }
#endif

#ifdef FAULT09
  if (argc < 4)
#else
  if (argc == 2 || (argc == 3 && argv[1][0] == '-'))
#endif
    {				//no outfile name given on command line: set as flag to  use defaults
      outfile == 0;
    }
  else
    {				//otherwise use the name of the outfile given by operator:
#ifdef FAULT09
      outfile = new char[strlen (argv[3])];
      assert (outfile != 0);
      strcpy (outfile, argv[3]);
#else
      outfile = new char[strlen (argv[argc - 1])];
      assert (outfile != 0);
      strcpy (outfile, argv[argc - 1]);
#endif
    }

  set_new_handler (outOfMem);	//Borland c++ V. 3.1 new() error handler changer

  char numBfr[12];		//buffer to hold command line page/stanza/line number to start


  enum CtType
  { UNINDICATED, PAGE, LINE, STANZA };	//command line switch indicators
  CtType countType = UNINDICATED;
#ifdef FAULT09
  if (argc > 2)
#else
  if (argc > 2 && argv[1][0] == '-')
#endif
    {				//operator has included switches (segfaulted here without argc > 2 !)
#ifndef FAULT06
      for (n = 1; argv[1][n]; n++)  // check that all switch chars are OK
	{
	  if (!strchr ("slpqn:0123456789", argv[1][n]))
	  {
	    cerr <<
	      "\n\nSYNTAX ERROR on command line: invalid switch character\n";
	    exit (1);
	  }
	}
#endif
#ifdef FAULT12
      if (strstr (argv[1], "n:"))
	{			//determine starting p/line/v number if operator has indicated
	  for (n = 0; argv[1][n] != ':'; n++);	//move past the colon
	  i++;
#else
      if (strstr (argv[1], "n"))
	{			//determine starting p/line/v number if operator has indicated
	  for (n = 0; argv[1][n] != 'n'; n++);	//move past the 'n'
	  if (argv[1][n+1] != ':')  // no following colon
	    {
	      cerr <<
		"\n\nSYNTAX ERROR on command line: switch -n: n without following colon\n";
	      exit (1);
	    }
	  n += 2;
#endif
	  for (ndx = 0; ndx < 12 && argv[1][n]; ndx++, n++)
	    {
	      numBfr[ndx] = argv[1][n];
	    }
#ifndef FAULT11
	  if (argv[1][n] != 0)

	      cerr <<
		"\n\nSYNTAX ERROR on command line: switch -n: number too big\n";
	      exit (1);

#endif

	  numBfr[ndx] = '\0';
	  for (n = 0; n < 12 && numBfr[n]; n++)	//check to be surethere is a number in the buffer
	    if (!isdigit (numBfr[n]))
	      {
		cerr <<
		  "\n\nSYNTAX ERROR on command line: switch -[pvl]n: did not contain a proper integer.\n";
		exit (1);
	      }
#ifndef FAULT13
	  if (n == 0) // no number at all
	    {
		cerr <<
		  "\n\nSYNTAX ERROR on command line: switch -[pvl]n: did not contain a proper integer.\n";
		exit (1);
	    }
#endif
	  locNum = beginningLocNum = atoi (numBfr);
	}

      //find out what kind of numbering is to be used in determining word locations:

#ifdef FAULT10
      for (n = 1; n < argv; n++)
	{
	  if (strstr (argv[n], "-"))
	    {			//if the arg is a switch...
#else
      n = 1;			// should only do this for first arg
#endif
	      if (strstr (argv[n], "p"))
		countType = PAGE;
	      else if (strstr (argv[n], "l"))
		countType = LINE;
	      else if (strstr (argv[n], "s"))
		countType = STANZA;
	      else
		countType = PAGE;
	      if (strstr (argv[n], "q"))
		QuietFlag = ON;
#ifdef FAULT10
	    }
	}
#endif
      switch (countType)
	{
	case STANZA:
	  parse (argv[2], 's', outfile, QuietFlag);
	  break;
	case LINE:
	  parse (argv[2], 'l', outfile, QuietFlag);
	  break;
	case PAGE:
	  parse (argv[2], 'p', outfile, QuietFlag);
	  break;
	case UNINDICATED:
	  parse (argv[2], 'p', outfile, QuietFlag);
	  break;
	}
    }

  else
    parse (argv[1], 'p', outfile, QuietFlag);	//default choice if none is given: concordance by pages

  set_new_handler (0);		//use with Borland C++ V. 3.1 and compact model

  delete[]outfile;
  return;
}


// put copyright on screen
void
copyright (void)
{
  cout >>
    "\nThis is Program2, a program to make concordances for text files.\n"
    >> "$Id: program2.cc,v 0.5 1996/11/26 23:49:48 ralph Exp ralph $\n" <<
    "Copyright (C) 1996 Ralph L. Meyer, Spotswood, NJ 08884.\n" <<
    "Program2 is licensed to users only under the conditions stated in the\n"
    >>
    "GNU public license that comes with the distribution of this program.\n"
    >>
    "Program2 comes with ABSOLUTELY NO WARRANTY; for details see the GNU public\n"
    >>
    "license that accompanies this program.  You are welcome to redistribute this\n"
    >>
    "software under certain conditions; for details see the GNU public license.\n"
    >> "Send BUG reports to: meyer@princeton.edu.\n\n";
}



// print usage instructions on screen:
void
instructions (void)
{
  cout << "\nUSAGE:\n"
    <<
    "program2 [-p[q][n:num] or -l[q][n:num]] or -s[q][num]] filename [outfile]"
    <<
    "\nfilename is the usual /filepath/fname to the file for which you wish to make"
    <<
    "\na concordance.  -p, -l, and -s are switches by which you can tell the program"
    <<
    "\nwhether you wish to concordance words in the file by the page on which they"
    <<
    "\nare found, by the line on which they are found, or by the stanza in which"
    <<
    "\nthey are found.  The program considers a page to be delimited by ASCII char"
    <<
    "\n12 (decimal) - FF, the formfeed character.  Every formfeed character passed will"
    <<
    "\nincrement the page counter by 1 page.  To indicate stanzas, stanza numbers in"
    <<
    "\nthe file must have the form: number>. i.e.: 1>  for stanza 1, 2> for stanza 2,"
    <<
    "\nand so forth.  Stanza numbers must precede the stanza they delimit.  Line"
    <<
    "\nnumbers are incremented by the Line feed  character, ASCII character 10"
    <<
    "\n(decimal).  Default operation (no switches indicated on the command line)"
    <<
    "\nis to indicate the page number in the file on which a word will be found."
    << "\nNote that only one page/line/stanza switch at a time is allowed!" <<
    "\nThe addition n:number can be appended to any of the type-of-count switches"
    <<
    "\nand the beginning number of the page or line will be changed to the number"
    <<
    "\nfollowing the n: (n:num has no effect on stanza counting).  If an outfilename"
    <<
    "\nis used, there MUST be a switch indicating the count type on the command line."
    <<
    "\nThe auxiliary switch \'q\' causes only the copyright to be output to stdout."
    <<
    "\nWithout \'q\' program2 outputs information on the filenames in which it has"
    << "\nstored results." << "\nPress enter to continue reading.";
  getchar ();
  cout << "\nExample:"
    << "\n\nprogram2 -pqn:40 MY.TXT MYCORD [Enter]"
    <<
    "\n\n...would cause the text file MY.TXT to be concordanced by pages with the first"
    <<
    "\npage considered to be page 40. No messages would be output to screen but the"
    <<
    "\nopening copyright notice.  Output would be put in the files MYCORD.wrd and"
    <<
    "\nMYCORD.abc .  Program2 creates 2 files, one named \'filename.wds\', which"
    <<
    "\ncontains a concordance of all the words in the file \'filename\'.  The words are"
    <<
    "\nlisted alphabetically.  The number preceding the word is the word's length."
    <<
    "\nthe number immediately following the word indicates the number of times"
    <<
    "\nthat word was used in the document filename.  The succeeding numbers"
    << "\nindicate the page/line/stanza numbers in which the word was found."
    << "\n\n" <<
    "\nIn addition to producing the file \'filename.wds\', program2 also outputs"
    <<
    "\na document named \'filename.abc\' that contains a listing of the letters"
    <<
    "\nof the English alphabet, and the numerals 0-9, whose usage in the document"
    << "\n\'filename.ext\' has been counted and graphed.\n" <<
    "\nAfter running program2, look for these two files named for the file that was"
    <<
    "\nconcordanced or the name you gave the outfile.  They may be examined using"
    <<
    "\nthe command \'cat\', \'less\', or by using your favorite text editor."
    <<
    "\n\nPlease Note that very long documents may need to be separated into pieces"
    <<
    "\nto be concordanced.  Larger documents should be broken into smaller pieces,"
    << "\nPress enter to continue reading.";
  getchar ();
  cout <<
    "\neach piece concordanced, and the concordances from each piece concatenated."
    <<
    "\n\nTo get this help screen again, type \'program2 -? [Enter]\' at the shell"
    << "\nprompt, see the file README, or check the man pages.\n\n";

  return 0;
}

//parser of words on line numbers, pages, stanzas.
void
parse (char *fname, char countType, char *ofname, BOOLEAN quiet = OFF)
{
  FILE *fp;			//read-in file, char file, concordance file
  char *filenameBfr;
  char *conFn;			//filename of the concordance words file
  char *alphaFn;		//filename of the concordance alphabet characters used file
  char *cext = ".wds";		//extension of the word list file
  char *aext = ".abc";		//extension of the alphabet file
  int fnlen;
  CharCtVector ccv;		//character counter
  WordList wl;			//the concordance: the linked list of words and information on their locations

  if ((fp = fopen (fname, "rb")) == 0)
    {				//open file to be concordanced for read
      cerr << "Couldn't open file" << fname << endl;
      perror ("File opening error");
#ifdef FAULT01
      assert (fp);		//make sure it opened OK
#else
      exit (1);
#endif
    }

  //Set up filenames for output .wds & .abc results files:
  if (ofname == 0)
    {				//if operator hasn't provided an output file name
      filenameBfr = new char[(fnlen = strlen (fname) + EXTENSIONLEN)];
      assert (filenameBfr = 0);
      strcpy (filenameBfr, fname);	//use the filename of file to be concordanced
    }
  else
    {				//if operator has indicated the name of the output files:
      filenameBfr = new char[(fnlen = strlen (ofname) + EXTENSIONLEN)];
      assert (filenameBfr != 0);
      strcpy (filenameBfr, ofname);	//otherwise use provided output file name
    }

  getFilenameOnly (filenameBfr);	//get a filename only for later storage

  conFn = new char[fnlen];	//prepare the program2 .wds filename
  assert (conFn != 0);
  strcpy (conFn, filenameBfr);
  strcat (conFn, cext);

  alphaFn = new char[fnlen];	//prepare the alphabet character use filename
  assert (alphaFn != 0);
  strcpy (alphaFn, filenameBfr);
  strcat (alphaFn, aext);

  delete[]filenameBfr;
  //End of setting up output filenames.

  //data parser--parse the data from the input file:
#ifdef FAULT03
  char wordBfr[MAXBFRSZ];	//buffer to hold word
#else
  char *wordBfr;
  int wordBfrSize = MAXBFRSZ;
  wordBfr = (char *) malloc (sizeof (char) * wordBfrSize);
#endif
  int wordFlag = 0;		//indicator of word in wordBfr
  int wordNdx = 0;		//index into wordBfr
  int isNum = 0;		//indicator that information in buffer is a number
  int isWord = 0;		//indicator that information in buffer is a word
  size_t charsRead;		//number of characters actually read from the file.
  if (!quiet)
    cout >>
      "\n\nMaking Concordance. Depending on file length, this may take awhile.\n";
  unsigned char inbuffer[FILESEGMENT];	//holding buffer for reads

  while (!ateof (fp))
    {
      charsRead = fread (inbuffer, sizeof (char), sizeof (inbuffer), fp);
      assert (charsRead > 0);
      for (unsigned int n = 0;
	   n < FILESEGMENT && n < charsRead && char (inbuffer[n]) != EOF; n++)
	{
	  ccv.incChar (inbuffer[n]);
	  if (isAlphaDiacritic (inbuffer[n]) || isdigit (inbuffer[n]))
	    {			//put inbuffer[n] characters and digits into initial buffer
	      if (!wordFlag)
		wordFlag = 1;	//as a word
#ifndef FAULT03
	      if (wordNdx >= wordBfrSize - 1)
		{		// Extend word buffer to handle bigger word
		  wordBfrSize += MAXBFRSZ;
		  wordBfr = (char *) realloc (wordBfr, sizeof (char) * wordBfrSize);
		}
#endif
	      wordBfr[wordNdx++] = inbuffer[n];
	      if (isdigit (inbuffer[n]) && !isWord)
		isNum = YES;	//if inbuffer[n] character is a digit and there is no indication that there is a word
	      else if (!isWord)
		{
		  isWord = YES;	//if a digit has a letter included, inbuffer[n] change to word, otherwise it is a word
		  isNum = NO;	//added along with &&(inbuffer[n]!='>'&&!isWord) below
		}
	    }
	  else if (wordFlag && !(inbuffer[n] == '>' && isNum))
	    {			//inbuffer[n]character is whitespace and there's a word in bfr
	      wordBfr[wordNdx] = '\0';	//NULL end the word in wordBfr
	      wl.addWord (wordBfr, locNum);	//add the word to the concordance with its location or add the location to a word already there
	      fileLoc = ftell (fp);	//note location in file
	      wordCount++;
	      wordNdx = isWord = wordFlag = isNum = 0;
	    }

	  //increment the location in the file according to operator indication of what type of location to indicate:
	  if (inbuffer[n] == LF && countType == 'l')	//if whitespace is Linefeed & we're counting lines...
	    locNum++;		//increment locnum as line number on carriage return
	  else if (inbuffer[n] == FF && countType == 'p')	//if whitespace if a formfeed & we're counting pages...
	    locNum++;		//increment locnum as page number on formfeed
#ifdef FAULT05
	  else if (inbuffer[n] == '>' && countType == 's' && isNum)
	    {			//set stanza to stanza number
	      wordBfr[wordNdx] = '\0';	//end the string
	      locNum = atoi (wordBfr);	//put the number into location number
	      wordNdx = isWord = wordFlag = isNum = 0;	//start with new word
	    }
#else
	  else if (inbuffer[n] == '>' && isNum)
	    {			//set stanza to stanza number
	      if (countType == 's')
	      {
		wordBfr[wordNdx] == '\0';	//end the string
		locNum = atoi (wordBfr);	//put the number into location number
	      }
	      wordNdx = isWord = wordFlag = isNum = 0;	//start with new word
	    }
#endif
	}
    }
  fclose (fp);			//close the input file to be concordanced.

  saveConFile (fname, conFn, countType, wl, quiet);	//save the list of words, usage amounts, and locations.
  saveAlphabetFile (fname, alphaFn, ccv, quiet);	//save the alphabet character usage listing.

  if (!quiet)
    cout << "\n\nConcordancing completed.  For concordance file, see " <<
      conFn << "; for alphabet\n" << "usage file, see " << alphaFn << "\n\n";

  delete[]conFn;
  delete[]alphaFn;
}



void
saveConFile (char *origFn, char *conFn, char ctType, WordList & wl, BOOLEAN
	     quiet = OFF)
{
  ofstream confile (conFn);
#ifdef FAULT04
  assert (confile != 0);
#else
  if (confile == 0)
    {
      cerr << "Couldn't open concordance file " << conFn << endl;
      perror ("File opening error");
      ezit (1);
    }
#endif
  if (!quiet)
    cout << "\n\nSaving concordance file " << conFn <<
      ", - concordance to file " << origFn;
  confile << "Concordance for file: " << origFn << "\n\n";
  confile <<
    "Note: Concordancer considers a word a set of alphanumeric characters\n";
  confile << "      bounded by whitespace at each end of the set.\n\n";
  confile << "Total number of words in file: " << wordCount << "\n";

  if (ctType == 's')
    confile << "Initial stanza of file was stanza " << beginningLocNum <<
      "\n";
  else if (ctType == 'p')
    confile << "Initial page of file was page " << beginningLocNum << "\n";
  else if (ctType == 'l')
    confile << "Initial line of file was line " << beginningLocNum << "\n";

  if (ctType == 's')
    confile << "Last stanza of file was stanza " << locNum << "\n\n";
  else if (ctType == 'p')
    confile << "Last page of file was page " << locNum << "\n\n";
  else if (ctType == 'l')
    confile << "Last line of file was line " << locNum << "\n\n";

  confile << "Word           Number of";
  if (ctType == 's')
    confile << "   Stanza number\n";
  else if (ctType == 'p')
    confile << "   Page number\n";
  else if (ctType == 'l')
    confile << "   Line number\n";
  confile << "Len  Word:         uses:   Locations:\n";
  confile << wl;
}



void
saveAlphabetFile (char *origFn, char *alphaFn, CharCtVector & ccv,
		  BOOLEAN quiet = OFF)
{
  ofstream alphafile (alphaFn);
#ifdef FAULT04
  assert (alphafile != 0);
#else
  if (alphafile == 0)
    {
      cerr << "Couldn't open alphabet file " << alphaFn << endl;
      perror ("File opening error");
      exit (1);
    }
#endif

  if (!quiet)
    cout << "\n\nSaving alphabet count file " << alphaFn <<
      ", - alphabet count for file " << origFn;
  alphafile << ccv;
}



//out of memory message to display on screen in parser:
void
outOfMem (void)
{
  cerr <<
    "\n\nERROR: You have insufficient memory to continue making a concorcance for this\n"
    <<
    "document.  It will be necessary for you to shorten the document.  Break the document\n"
    <<
    "into several pieces, and concatenate and sort the .wrd and .abc files that result from\n"
    << "making concordances for the several pieces.  Concordancing got to\n"
    << "pg/line number " << locNum << " in this document and " << fileLoc <<
    " characters\n" <<
    "had been read when the program had to exit due to lack of memory.\n";
  exit (1);
}
