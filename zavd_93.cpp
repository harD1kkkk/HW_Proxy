// zavd_93.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream> 
using namespace std;

class Document {
protected:
    string text = "";
public:
    Document(string text_) :text(text_) { }
    void readDocument() {
        cout << "Text: " << text << endl;
    }
    void writeDocument() {
        cin >> text;
    }
};

class DocumentAccess {
public:
    virtual void readDocument() = 0;
    virtual void writeDocument() = 0;
};

class RealDocumentAccess : public DocumentAccess {
private:
    Document* document;
public:
    RealDocumentAccess(Document* document_) {
        document = document_;
    }
    void readDocument()override {
        document->readDocument();
        cout << "You read text Without a limit" << endl;
    }
    void writeDocument()override {
        cout << "Write a text Withot a limit: ";
        document->writeDocument();
        cout << "You wrote a text Without a limit" << endl;
    }
};

class ProxyDocumentAccess : public DocumentAccess {
private:
    Document* document;
    string accessLevel;
public:
    ProxyDocumentAccess(Document* document_, string accessLevel_) {
        document = document_;
        accessLevel = accessLevel_;
    }
    void readDocument()override {
        if (accessLevel == "123qwe") {
            document->readDocument();
            cout << "Successfull" << endl;
        }
        else {
            cout << "Access denied" << endl;
        }
    }
    void writeDocument()override {
        if (accessLevel == "123qwe") {
            cout << "Write text: ";
            document->writeDocument();
            cout << "Successfull" << endl;
        }
        else {
            cout << "Access denied" << endl;
        }
    }
};

int main() {
    while (true) {
        Document* doc = new Document("");
        cout << "Enter text: ";
        doc->writeDocument();
        int choice;
        cout << "Make choice 1 - RealDocumentAccess, 2 - ProxyDocumentAccess, 3 - exit" << endl;
        cout << "choice: "; cin >> choice;
        if (choice == 1) {
            cout << "Case 1: RealDocumentAccess" << endl; 
            RealDocumentAccess realdoc(doc);
            realdoc.readDocument();
            realdoc.writeDocument();
            cout << endl; 
        }
        else if (choice == 2) {
            cout << "Case 2: ProxyDocumentAccess" << endl; 
            string pass = "";
            cout << "Enter password: "; cin >> pass;
            ProxyDocumentAccess proxydoc(doc, pass);
            proxydoc.readDocument();
            proxydoc.writeDocument();
            cout << endl; 
        }
        else if (choice == 3) {
            cout << "Goodbye" << endl;
            return 0;
        }
        else {
            cout << "Unknown option" << endl;
        }
    }
}
