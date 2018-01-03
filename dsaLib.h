/*
 * =========================================================================================
 * Name        : dsaLib.h
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - Bach Khoa University
 * Description : library for Assignment 2 - Data structures and Algorithms - Fall 2017
 * =========================================================================================
 */

#ifndef A02_DSALIB_H
#define A02_DSALIB_H

#include <string>
#include <math.h>
#include <vector>

using namespace std;


class DSAException {
    int     _error;
    string  _text;
public:

    DSAException() : _error(0), _text("Success") {}
    DSAException(int err) : _error(err), _text("Unknown Error") {}
    DSAException(int err, const char* text) : _error(err), _text(text) {}

    int getError() { return _error; }
    string& getErrorText() { return _text; }
};

template <class T>
struct L1Item {
    T data;
    L1Item<T> *pNext;
    L1Item() : pNext(NULL) {}
    L1Item(T &a) : data(a), pNext(NULL) {}
};

template <class T>
class L1List {
    L1Item<T>   *_pHead;// The head pointer of linked list
    size_t      _size;// number of elements in this list
public:
    L1List() : _pHead(NULL), _size(0) {}
    ~L1List() {};
    
    L1Item<T>*  getHead() {
        return _pHead;
    }

    void    clean();
    bool    isEmpty() {
        return _pHead == NULL;
    }
    size_t  getSize() {
        return _size;
    }

    T&      at(int i);
    T&      operator[](int i);

    bool    find(T& a, int& idx);
    T*      find(T& a);
    T*      findLast(T& a);
    int     insert(int i, T& a);
    int     remove(int i);
    int     removeAll(T& a);

    int     push_back(T& a);
    int     insertHead(T& a);

    int     removeHead();
    int     removeLast();

    void    reverse();

    void    traverse(void (*op)(T&)) {
        L1Item<T>   *p = _pHead;
        while (p) {
            op(p->data);
            p = p->pNext;
        }
    }
    void    traverse(void (*op)(T&, void*), void* pParam) {
        L1Item<T>   *p = _pHead;
        while (p) {
            op(p->data, pParam);
            p = p->pNext;
        }
    }
};

// Clean All node Linked List
// No need return
template <class T>
void L1List<T>::clean() {
    while(!isEmpty()) {
        removeHead();
    }
}


// Access Data in Linked List at i
template <class T>
T& L1List<T>::at(int i)
{
    L1Item<T> *p = _pHead;
    if(i<=_size)
    {
        int count = 0;
        while(count<i)
        {
            count++;
            p=p->pNext;
        }
    }
    return p->data;
}

// Access Data in Linked List at i
template <class T>
T& L1List<T>::operator[](int i)
{
    L1Item<T> *p = _pHead;
    if(i<=_size)
    {
        int count = 0;
        while(count<i)
        {
            count++;
            p=p->pNext;
        }
    }
    return _pHead->data;
}

template <class T>
bool L1List<T>::find(T& a, int& idx){
    return true;
}

// Find Data in Linked List
// If finding success return Node have found data
// If not return NULL
template <class T>
T* L1List<T>::find(T& a)
{
    L1Item<T>* p = _pHead;
    while(p)
    {
        if(p->data == a)
        {
            return p;
        }
        p=p->pNext;
    }
    return NULL;
}


// Function findLast
template <class T>
T*  L1List<T>::findLast(T& a) {
    return NULL;
}

// Insert Data in node i(th) with data a
template <class T>
int  L1List<T>::insert(int i, T& a){
    return 0;
}

// Delete Data at i
template <class T>
int  L1List<T>::remove(int i) {
    return 0;
}

/// Remove All Linked List
template <class T>
int  L1List<T>::removeAll(T& a){
    while(!isEmpty()) {
        removeHead();
    }
    return 0;
}

/// Insert item to the end of the list
/// Return 0 if success
template <class T>
int L1List<T>::push_back(T &a) {
    if (_pHead == NULL) {
        _pHead = new L1Item<T>(a);
    }
    else {
        L1Item<T>   *p = _pHead;
        while (p->pNext) p = p->pNext;
        p->pNext = new L1Item<T>(a);
    }
    
    _size++;
    return 0;
}


/// Insert item to the front of the list
/// Return 0 if success
template <class T>
int L1List<T>::insertHead(T &a) {
    L1Item<T>   *p = new L1Item<T>(a);
    p->pNext = _pHead;
    _pHead = p;
    _size++;
    return 0;
}

/// Remove the first item of the list
/// Return 0 if success
template <class T>
int L1List<T>::removeHead() {
    if(_pHead) {
        L1Item<T>* p = _pHead;
        _pHead = p->pNext;
        delete p;
        _size--;
        return 0;
    }
    return -1;
}

/// Remove the last item of the list
/// Return 0 if success
template <class T>
int L1List<T>::removeLast() {
    if(_pHead) {
        if(_pHead->pNext) {
            L1Item<T>* prev = _pHead;
            L1Item<T>* pcur = prev->pNext;
            while(pcur->pNext) {
                prev = pcur;
                pcur = pcur->pNext;
            }
            delete pcur;
            prev->pNext = NULL;
        }
        else {
            delete _pHead;
            _pHead = NULL;
        }
        _size--;
        return 0;
    }
    return -1;
}

// Reverse All Linked List
template <class T>
void  L1List<T>::reverse() {
    if (_pHead == NULL) return;
    
    L1Item<T> *prev = new L1Item<T>; prev = NULL;
    L1Item<T> *curr = new L1Item<T>; curr = NULL;
    L1Item<T> *next = new L1Item<T>; next = NULL;
    
    curr = _pHead;
    while (curr != NULL){
        next = curr->pNext;
        curr->pNext = prev;
        prev = curr;
        curr = next;
    }
    // now let the head point at the last node (prev)
    _pHead = prev;
}


/************************************************************************
 * This section is for AVL tree
 ************************************************************************/
template <class T>
struct AVLNode {
    T           _data;
    AVLNode<T>   *_pLeft, *_pRight;
#ifdef AVL_USE_HEIGHT
    int         _height;
    AVLNode(T &a) : _data(a), _pLeft(NULL), _pRight(NULL), _height(1) {}
#else
    int         _bFactor;
    AVLNode(T &a) : _data(a), _pLeft(NULL), _pRight(NULL), _bFactor(0) {}
#endif
};

template <class T>
class AVLTree {
    AVLNode<T> *_pRoot;
public:
    AVLTree() : _pRoot(NULL) {}
    ~AVLTree() { destroy(_pRoot); }

    bool find(T& key, T* &ret) { return find(_pRoot, key, ret); }
    bool insert(T& key) { return insert(_pRoot, key); }
    bool remove(T& key) { return remove(_pRoot, key); }
    void traverseNLR(void (*op)(T&)) { traverseNLR(_pRoot, op); }
    void traverseLNR(void (*op)(T&)) { traverseLNR(_pRoot, op); }
    void traverseLRN(void (*op)(T&)) { traverseLRN(_pRoot, op); }

protected:
    
///////// Destroy pRoot ///////////////////////////////////////////////////////////
    
    void destroy(AVLNode<T>* &pR) {
        return;
    }
    
///////// Find data in AVL tree //////////////////////////////////////////////////
    
    bool find(AVLNode<T> *pR, T& key, T* &ret) {
        return true;
    }
    
///////// Insert Data in AVL tree //////////////////////////////////////////////////
    
    bool insert(AVLNode<T>* &pR, T& a) {
        if(pR==NULL) { pR = new AVLNode<T>(a); return true; }
        if(a<pR->data)
        {
            if(insert(pR->_pLeft, a)==false) return false;
            return balanceLeft(pR);
        }
        else
        {
            if(insert(pR->_pRight, a)==false) return false;
            return balanceRight(pR);
        }
    }
    
///////// Remove Data in AVL tree //////////////////////////////////////////////////
    
    bool remove(AVLNode<T>* &pR, T& a) {
        if(pR==NULL) return false;
        if(a<pR->data)
        {
            if(remove(pR->_pLeft, a)==false) return false;
            if(pR->_bFactor==-1) { pR->_bFactor=0; return true; }
            if(pR->_bFactor==0) { pR->_bFactor=1; return false; }
            return !balanceRight(pR);
        }
        if(a>pR->data)
        {
            if(remove(pR->_pRight, a)==false) return false;
            if(pR->_bFactor==1) { pR->_bFactor=0; return true; }
            if(pR->_bFactor==0) { pR->_bFactor=-1; return false; }
            return !balanceLeft(pR);
        }
        if(pR->_pLeft==NULL && pR->_pRight==NULL)
        {
            delete pR; pR=NULL; return true;
        }
        if(pR->_pLeft==NULL)
        {
            AVLNode<T>* p=pR;
            pR=pR->_pRight;
            delete p; p=NULL;
            return true;
        }
        if(pR->_pRight==NULL)
        {
            AVLNode<T>* p=pR;
            pR=pR->_pLeft;
            delete p; p=NULL;
            return true;
        }
        AVLNode<T>* p=pR->_pRight;
        while(p->_pLeft) p = p->_pLeft;
        pR->data = p->data;
        if(remove(p->data, pR->_pRight))
        {
            if(pR->_bFactor==1) { pR->_bFactor=0; return true; }
            if(pR->_bFactor==0) { pR->_bFactor=-1; return false; }
            return !balanceleft(pR);
        }
        return true;
    }
    
///////// Traverse Node-Left-Right AVL tree //////////////////////////////////////////////////
    
    void traverseNLR(AVLNode<T> *pR, void (*op)(T&)) {
        return;
    }
    
///////// Traverse Left-Node-Right AVL tree //////////////////////////////////////////////////
    
    void traverseLNR(AVLNode<T> *pR, void (*op)(T&)) {
        return;
    }
    
///////// Traverse Left-Right-Node AVL tree
    void traverseLRN(AVLNode<T> *pR, void (*op)(T&)) {
        return;
    }

    
///////// Rotation Left //////////////////////////////////////////////////////////////////////
    
    void rotLeft(AVLNode<T>* &pR) {
        if(pR==NULL) return;
        if(pR->_pRight==NULL) return;
        AVLNode<T>* p = pR->_pRight;
        pR->_pRight = p->_pLeft;
        p->_pLeft = pR;
        pR=p;
    }
    
///////// Rotation Right ////////////////////////////////////////////////////////////////////
    
    void rotRight(AVLNode<T>* &pR) {
        if(pR==NULL) return;
        if(pR->_pLeft==NULL) return;
        AVLNode<T>* p = pR->_pLeft;
        pR->_pLeft = p->_pRight;
        p->_pRight = pR;
        pR=p;
    }
    
///////// Rotation Left-Right ///////////////////////////////////////////////////////////////
    
    void rotLR(AVLNode<T>* &pR) {
        rotLeft(pR->_pLeft);
        rotRight(pR);
    }
    
///////// Rotation Right-Left //////////////////////////////////////////////////////////////
    
    void rotRL(AVLNode<T>* &pR) {
        rotRight(pR->_pRight);
        rotLeft(pR);
    }

    
///////// Balance Left /////////////////////////////////////////////////////////////////////
    
    bool balanceLeft(AVLNode<T>* &pR) {
        if(pR->_bFactor==0) { pR->_bFactor=-1; return true; }
        if(pR->_bFactor==1) { pR->_bFactor=0; return false; }
        if(pR->_pLeft->_bFactor==-1) {
            rotRight(pR);
            pR->_bFactor=pR->_pRight->_bFactor=0;
            return false;
        }
        rotLR(pR);
        if(pR->_bFactor==-1){
            pR->_bFactor=pR->_pLeft->_bFactor=0;
            pR->_pLeft->_bFactor=1;
            return false;
        }
        pR->_bFactor=pR->_pRight->_bFactor=0;
        pR->_pLeft->_bFactor=-1;
        return false;
    }
    
///////// Balance Right ////////////////////////////////////////////////////////////////////////
    
    bool balanceRight(AVLNode<T>* &pR) {
        if(pR->_bFactor==0) { pR->_bFactor=1; return true; }
        if(pR->_bFactor==-1) { pR->_bFactor=0; return false; }
        if(pR->_pRight->_bFactor==1) {
            rotLeft(pR);
            pR->_bFactor=pR->_pLeft->_bFactor=0;
            return false;
        }
        rotRL(pR);
        if(pR->_bFactor==1){
            pR->_bFactor=pR->_pRight->_bFactor=0;
            pR->_pRight->_bFactor=-1;
            return false;
        }
        pR->_bFactor=pR->_pRight->_bFactor=0;
        pR->_pLeft->_bFactor=1;
        return false;
    }
};



#endif //A02_DSALIB_H
