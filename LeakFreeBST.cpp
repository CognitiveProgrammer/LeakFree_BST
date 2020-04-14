/*
 * MIT Licence
 * Copyright 2017 @Deepak K Gupta [nickname: Daksh] (www.CodesBay.com)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files(the "Software"), to deal in the
 * Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and / or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so, subject to the following conditions :
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH
 * THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
 
#include <iostream> 
#include <vector>

using namespace std; 

// The Generic Binary Search Tree with Left and Right Subtree
template<typename dataType>
struct bst {
    dataType data;
    int leftIndex;
    int rightIndex;
};


// The BST Helper class with public and helper function to Insert and 
// Traverse the Binary Search Tree

template<typename dataType>
class bstHelper {
    bst<dataType> theBst;
    vector<bst<dataType>> treeVector;

    // Creates a Node
    void MakeNode( dataType data) {
        bst<dataType> treeNode { data, -1, -1 };
        treeVector.push_back(treeNode);
    }
    // Create and sets the newly created node as left node of
    // the current node
    void setleft(unsigned int currIndex, dataType aData)
    {
        unsigned int leftIndex = treeVector.size();
        treeVector[currIndex].leftIndex = leftIndex;
        this->MakeNode(aData);
    }
    // Create and sets the newly created node as right node of
    // the current node
    void setright(unsigned int currIndex, dataType aData)
    {
        unsigned int rightIndex = treeVector.size();
        treeVector[currIndex].rightIndex = rightIndex;
        this->MakeNode(aData);
    }

public:
    // Public function used for inserting the data into the BST
    void Insert(dataType aData)
    {
        // if its empty, create the first one
        if(treeVector.size() == 0)
        {
            this->MakeNode(aData);
            return;
        }
        // Loop through, find or Insert the data 
        unsigned int currentIdx = 0;
        while ( currentIdx < treeVector.size() )
        {
            if(aData <= treeVector[currentIdx].data)
            {
                if( treeVector[currentIdx].leftIndex == -1)
                {
                    setleft(currentIdx, aData);
                    break;
                }
                else
                    currentIdx = treeVector[currentIdx].leftIndex;
            }
            else
            {
                if(treeVector[currentIdx].rightIndex == -1)
                {
                    setright(currentIdx, aData);
                    break;
                }
                else
                    currentIdx = treeVector[currentIdx].rightIndex;
            }
        }
    }
    // Recursive In-Order Traversal of the Data
    void InTrav(unsigned int Idx)
    {
        if(treeVector[Idx].leftIndex != -1)
            InTrav(treeVector[Idx].leftIndex );
        cout<<treeVector[Idx].data<<endl;
        if( treeVector[Idx].rightIndex != -1)
            InTrav(treeVector[Idx].rightIndex);
    }

};

// The main test function
int main() {
    bstHelper<int> tree;
    tree.Insert(0);
    tree.Insert(6);
    tree.Insert(40);
    tree.Insert(35);
    tree.Insert(16);
    tree.Insert(7);
    tree.Insert(4);
    tree.Insert(52);
    tree.Insert(99);
    tree.Insert(9);
    tree.Insert(79);
    tree.Insert(17);

    tree.InTrav(0);

    return 0;
}
