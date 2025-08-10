
#include "tries.cpp"

int main() {
    int choice;
    cin >> choice;
    Trie t;

    while (choice != -1) {
        string word;
        bool ans;
        switch (choice) {
            case 1:  // insert
                cin >> word;
                t.insert(word);
                break;
            case 2:  // search
                cin >> word;
                cout << (t.search(word) ? "true\n" : "false\n");
                break;
            case 3:
                cin>>word;
                t.erase(word);
                cout<<" done "<<endl;
                break;
            default:
                return 0;
        }
        cin >> choice;
    }

    return 0;
}