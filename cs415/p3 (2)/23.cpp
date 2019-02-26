//Description: Implementations for the binary search tree class.

#include "23.h"
#include "time.h"
#include <iomanip>
#include <sstream>

//Constructor
TTT::TTT(){
    root = NULL;
}

//Returns true if there are no nodes in the tree
bool TTT::isEmpty(){
    return root == NULL;
}

//Used to implement the search function in the main
//program.
void TTT::contains() const{
   string input;
   node *foundNode = NULL;
   cout << "Search word: ";
   cin >> input;
    	if(containsHelper(input, root, foundNode)){
            if(foundNode->lkey.compare(input) == 0){ //in left key
                cout << "Line Numbers: " << foundNode->llines[0];
                for(int i = 1; i < foundNode->llines.size(); i++)
                cout << ", " <<foundNode->llines[i]; 
                cout << '\n';
            }
            else{ //in right key
                cout << "Line Numbers: " << foundNode->rlines[0];
                for(int i = 1; i < foundNode->rlines.size(); i++)
                cout << ", " <<foundNode->rlines[i]; 
                cout << '\n';
            }
        }
	else
	    cout << '\"' << input <<"\" is not in the document\n";
}

//Prints the index to the supplied receiver, either
//cout or the output file
void TTT::printTree(ostream & out) const {
	out << "Binary Search Tree Index:\n-------------------------\n";
	printTreeHelper(root, out);
}

double TTT::searchIndex(vector<string> keys) {
	bool contains = false;

	double totalTime, finishTime, startTime = clock();

	for (auto i = keys.begin(); i != keys.end(); ++i) {
		containsHelper(*i, root, root);
	}

	finishTime = clock();
	totalTime = (double)(finishTime - startTime) / CLOCKS_PER_SEC;
	return totalTime;
}
//Receives the specified input file and constructs 
//the actual tree. Prints a message when finished.
void TTT::buildTree(ifstream & input, bool printmsg){
	int line = 1, numWords = 0, distWords = 0, treeHeight = 0;
	stringstream tempWord;
	double totalTime, finishTime, startTime = clock();
	while (!input.eof()) {
		string tempLine, tempWord;

		//Read a whole line of text from the file
		getline(input, tempLine);
		for (int i = 0; i < tempLine.length(); i++) {
		    //Insert valid chars into tempWord until a delimiter( newline or space) is found
		    while (tempLine[i] != ' '&& tempLine[i] != '\n' && i < tempLine.length() ) {
			tempWord.insert(tempWord.end(), tempLine[i]);
			i++;
		    }
		   
            //Trim any punctuation off end of word. Will leave things like apostrophes
            //and decimal points
            while(tempWord.length() > 0 && !isalnum(tempWord[tempWord.length() - 1]))
			    tempWord.resize(tempWord.size() -1);   
			
            if (tempWord.length() > 0)
            {
                //Once word is formatted,call insert with the word, the line of the input
                //file it came from, the root of our tree, and the distinct word counter
                root = insertHelper(tempWord, line, root, distWords);
                //Increment our total number of words inserted
                numWords++;
                //Clear out tempWord so we can use it again
                tempWord.clear();
		    }
			
		}
		line++;
	}
	//Do time and height calculation
	finishTime = clock();
	totalTime = (double) (finishTime - startTime)/CLOCKS_PER_SEC;
	treeHeight = findHeight(root);

	if (printmsg) {
		//Print output
		cout << setw(40) << std::left;
		cout << "Total number of words: " << numWords << endl;

		cout << setw(40) << std::left
			<< "Total number of distinct words: " << distWords << endl;

		cout << setw(40) << std::left
			<< "Total time spent building index: " << totalTime << endl;

		cout << setw(40) << std::left
			<< "Height of TTT is : " << treeHeight << endl;
	}
 
}

bool TTT::node::isLeaf() {
	return (left == NULL && right == NULL && center == NULL);
}

TTT::node * TTT::insertHelper(const string &x, int line, node *& rt, int &distWord) {
	node * retval;
	if (rt == NULL) { // Empty tree : make new leaf at root
		rt = new node(x, NULL, NULL, NULL);
		rt->llines.push_back(line);
		distWord++;
		return rt;
	}

	if (x.compare(rt->lkey) == 0) {
		rt->llines.push_back(line);
		return rt;
	}
	if (x.compare(rt->rkey) == 0) {
		rt->rlines.push_back(line);
		return rt;
	}

	if (rt->isLeaf()) { // at leaf: insert here
		node * n = new node(x, NULL, NULL, NULL);
		n->llines.push_back(line);
		distWord++;
		return rt->add(n);
	}
	if (x.compare(rt->lkey) < 0) { //insert left
		retval = insertHelper(x, line, rt->left, distWord);
		if (retval == rt->left) return rt;
		else return rt->add(retval);
	}
	else if ((rt->rkey == "") || (x.compare(rt->rkey) < 0)) {
		retval = insertHelper(x, line, rt->center, distWord);
		if (retval == rt->center) return rt;
		else return rt->add(retval);
	}
	else{ //insert right
		retval = insertHelper(x, line, rt->right, distWord);
		if (retval == rt->right) return rt;
		else return rt->add(retval);
	}
}


TTT::node* TTT::node::add(node * t) {
	if (rkey == "") { //only one key, add here
		if (lkey.compare(t->lkey) < 0) {
			rkey = t->lkey; rlines = t->llines;
			center = t->left; right = t->center;
		}
		else {
			rkey = lkey; rlines = llines; right = center;
			lkey = t->lkey; llines = t->llines;
			center = t->center;
			left = t->left;
		}
		return this;
	}
	else if (lkey.compare(t->lkey) >= 0) { //add left
		TTT::node * n = new node(lkey, t, this, NULL);
		n->llines = llines;
		//t->left = left;
		left = center; center = right; right = NULL;
		lkey = rkey; llines = rlines; rkey = ""; rlines.clear();
		return n;
	}
	else if (rkey.compare(t->lkey) >= 0){ //add center
		t->center = new node(rkey, t->center, right, NULL);
		t->center->llines = rlines;
		center = t->left;
		t->left = this;
		rkey = ""; rlines.clear(); right = NULL;
		return t;
	}
	else { //add right
		TTT::node * n = new node(rkey, this, t, NULL);
		n->llines = rlines;
		//t->left = right;
		right = NULL; rkey = ""; rlines.clear();
		return n;
	}
}
        
    

//Used by contains() to see if a words is present or not. Will
//give contains() a pointer to the found node so that contains()
//can prints the lines the word was found on.
bool TTT::containsHelper(const string & x, node * t, node * &result) const{
	if (t == NULL)
		return false;
	if (x.compare(t->lkey) == 0){
	    result = t;
 	    return true;
	}
	//can remove this check for empty rkey probably
    if ((t->rkey != "") && (x.compare(t->rkey) == 0)){
        result = t;
        return true;
    }
	if (x.compare(t->lkey) < 0) // Search left
		return containsHelper(x, t->left, result);
	else if (t->rkey == "") // Search center
		return containsHelper(x, t->center, result);
	else if (x.compare(t->rkey) < 0) // Search center
		return containsHelper(x, t->center, result);
    else					// Search right
        return containsHelper(x, t->right, result);
}

//Called by printTree(), does the actual formatted printing
void TTT::printTreeHelper(node *t, ostream & out) const{
    if(t == NULL)
		return;
	else {
        //print left tree
		printTreeHelper(t->left, out);
        //print left key
		out << setw(30) << std::left;
		out << t->lkey << " " << t->llines[0];
		for (int i = 1; i < t->llines.size(); i++)
			out << ", " << t->llines[i];
		out << endl;
        //print center tree
        printTreeHelper(t->center, out);
        //print right key
        out << setw(30) << std::left;
		if (t->rlines.size() != 0) {
			out << t->rkey << " " << t->rlines[0];
			for (int i = 1; i < t->rlines.size(); i++)
				out << ", " << t->rlines[i];
			out << endl;
		}
        //print right tree
		printTreeHelper(t->right, out);
	}
}

//Returns height of tree. If tree has only one node, height is 1    
int TTT::findHeight(node *t){
    if(t == NULL)
	return 0;
    else{
	int leftHeight = findHeight(t->left), rightHeight = findHeight(t->right);
	if(leftHeight > rightHeight)
	    return(leftHeight+1);
	else 
	    return(rightHeight+1);
    }
}
