#pragma once
template <class T>
class tree {
public:	
	class node {
	public:
		T value;
		int nrChild;
		node** child;
        node* parent;
	};
	node* root;
    void insert(node* parinte, T value, int index);
	void add_node(node*parinte, T value);
	node get_node(node* parinte,int index);
    void delete_node(node* parinte);
    void sort(node* parent, bool(*compare)(T, T));
    node find(node* nod, T value);
    bool compare(T x, T y);
    int count(node* nod);
	tree();
	//~tree();
};

template<typename T>
tree<T>::tree() {
    this->root = new node; 
    this->root->value = T(); 
    this->root->nrChild = 0;
    this->root->child = nullptr;
    this->root->parent = nullptr;
}

template<typename T>
void tree<T>::add_node(node* parent, T value) {
    node* de_adaugat = new node;
    de_adaugat->value = value;
    de_adaugat->nrChild = 0;
    de_adaugat->child = nullptr;
    de_adaugat->parent = parent;

    if (parent == nullptr) {
        this->root = de_adaugat;
    }
    else {
        node** newChild = new node * [parent->nrChild + 1];
        for (int i = 0; i < parent->nrChild; i++) {
            newChild[i] = parent->child[i];
        }
        newChild[parent->nrChild] = de_adaugat;
        if (parent->child == nullptr);
        delete[] parent->child;
        parent->child = newChild;
        parent->nrChild++;
    }
}
template<typename T>
typename tree<T>::node tree<T>::get_node(node* parent, int index) {
    if (parent == nullptr)
        return *root;
    else
        return *(parent->child[index]); 
}

template<typename T>
void tree<T>::delete_node(node* nod) {
    if (nod->nrChild == 0) {//daca nodu care vr sa i dau delete n are copii
        for (int i = 0; i < nod->parent->nrChild; i++) {//parcurg vectoru de copii a parintelui lui
            if (nod->parent->child[i] == nod) {//cand il gasesc in mut la stanga toate elementele la stanga de dupa el 
                for (int j = i; j < nod->parent->nrChild - 1; j++) {
                    nod->parent->child[j] = nod->parent->child[j + 1];
                }
                nod->parent->nrChild--;//scad counteru ca am sters elementu si dupa sterg nodu propriu zis
                delete nod;
                return;
            }
        }
    }
    else {//daca nodu meu are si copii am sa i sterg recursiv copiii
        for (int i = 0; i < nod->nrChild; i++) {
            delete_node(nod->child[i]);
        }
        if (nod->parent != nullptr) {//acm reiau ce am facut mai sus ca sa sterg nodu + el din lista de copii al parintelui lui
            for (int i = 0; i < nod->parent->nrChild; i++) {
                if (nod->parent->child[i] == nod) {
                    for (int j = i; j < nod->parent->nrChild - 1; j++) {
                        nod->parent->child[j] = nod->parent->child[j + 1];
                    }
                    nod->parent->nrChild--;
                    delete nod;
                    return;
                }
            }
        }
        else {//daca e un nod singur /radacina fara copii
            delete nod;
        }
    }
}


template<typename T>
int tree<T>::count(node* nod) {
    if (nod == nullptr)
        return count(this->root);
    else return nod->nrChild;
}

template<typename T>
void tree<T>::insert(node* parinte, T value, int index) {
    node* de_adaugat = new node;
    de_adaugat->value = value;
    de_adaugat->nrChild = 0;
    de_adaugat->child = nullptr;
    de_adaugat->parent = parinte;

    node** newChild = new node * [parinte->nrChild + 1];
    int copyIndex = 0;
    for (int i = 0; i < parinte->nrChild; i++) {  //parcurg vectoru de copii a parintelui
        if (i == index) {
            newChild[i] = de_adaugat;
        }
        else {
            newChild[i] = parinte->child[copyIndex];
            copyIndex++;
        }
    }
    newChild[parinte->nrChild] = de_adaugat;

    delete[] parinte->child;
    parinte->child = newChild;
    parinte->nrChild++;
}


template<typename T>
void tree<T>::sort(node* parent, bool(*comp)(T, T)) {
    for (int i = 0;i < parent->nrChild - 1;i++)
        for (int j = i + 1;j < parent->nrChild;j++)
            if (comp(parent->child[i]->value, parent->child[j]->value))
            {
                node* aux = new node;
                aux=parent->child[i];
                parent->child[i]=parent->child[j];
                parent->child[j]=aux;
            }

}

template<typename T>
typename tree<T>::node tree<T>::find(node* nod, T value) {
  
    for (int i = 0; i < nod->nrChild; i++)
    {
        if (nod->child[i]->value == value)
        {
          return *(nod->child[i]);
          break;
        }
        find(nod->child[i], value);
    }
}


