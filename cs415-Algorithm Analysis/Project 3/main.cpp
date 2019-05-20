//CS-415 Fall 2018 Project 3
//Group Members: Brandon Adamson-Rakidzich
//				 Christian Esperon


//Description: Takes a text file supplied by the user
//             and turns it into a word index, implemented
//             through the use of a BST 

#include <iostream>
#include <fstream>
#include "bst.h"
#include "23.h"
using namespace std;

int main(int argc, char* argv[]) {
    char mode_choice;
	int choice;
	if (argc != 2) {
	    cout << "Incorrect input. Correct format: ./<exectuable.out> <inputtext.txt>\n";
	    return 1;
	}

	ifstream input(argv[1]);

	if(input.is_open()){
        
        mode_choice = 'z';
        cout << "Options: (a) BST, (b) 2-3 Tree, (c) Compare BST and 2-3 Tree\n";
        cin >> mode_choice;
        
        //BST
        if(mode_choice == 'a'){
            BST myTree;
            myTree.buildTree(input, true);
            input.close();
            while(1){
                choice = 0;
                cout <<"Options: (1) display index, (2) search, (3) save index, (4) quit\n";
                cin >> choice;

                //Print index
                if(choice == 1)
                    myTree.printTree(cout);
               
                //Search index for a word
                else if(choice == 2)
                    myTree.contains();

                //Save index
                else if(choice == 3){
                string outputFile;
                    cout << "Enter a filename to save your index to (Suggested: <filename>.txt) : ";
                cin >> outputFile;
                ofstream output(outputFile.c_str());
                    myTree.printTree(output);
                    output.close();
                cout << "Saved\n";
                }

                //Quit	
                else
                break;
                }
     
        }
        //2-3
        if(mode_choice == 'b'){
			TTT myTree;
			myTree.buildTree(input, true);
			input.close();
			while (1) {
				choice = 0;
				cout << "Options: (1) display index, (2) search, (3) save index, (4) quit\n";
				cin >> choice;

				//Print index
				if (choice == 1)
					myTree.printTree(cout);

				//Search index for a word
				else if (choice == 2)
					myTree.contains();

				//Save index
				else if (choice == 3) {
					string outputFile;
					cout << "Enter a filename to save your index to (Suggested: <filename>.txt) : ";
					cin >> outputFile;
					ofstream output(outputFile.c_str());
					myTree.printTree(output);
					output.close();
					cout << "Saved\n";
				}

				//Quit	
				else
					break;
			}

        }
        //both
        if(mode_choice == 'c'){
			TTT ttTree;
			BST bstTree;
			ttTree.buildTree(input, false);
			ifstream input(argv[1]);
			bstTree.buildTree(input, false);
			input.close();
			cout << endl;
			cout << "Total time taken by BST : " << bstTree.searchIndex(bstTree.returnIndex()) << endl;
			cout << "Total time taken by 2 - 3 Tree : " << ttTree.searchIndex(bstTree.returnIndex()) << endl;
			
        }
    }
	else{
	    cout << "Invalid File Name. Restart Program.\n";
	    return 2;
        }
	return 0;
}
