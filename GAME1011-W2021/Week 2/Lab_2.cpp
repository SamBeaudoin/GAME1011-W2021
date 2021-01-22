#include <iostream>

using namespace std;
/* Dynmic Arrays
 * New[]
 * Delete[]
 * const
 * this
 * Copy Constructor
 * Memberwise Copy
 *
 * Create Document class
 * Document will store some text data
 * Document will store dtnamic array of data
 * will hide the data, and instead offer public Accessor and mutator functions
 *
 * create Reader class
 * Reader will access and print data from document
 * no other functions
 */

// We can print the document by passing it to the reader

// 

class Document
{
private:	// Hidden from everything else
	char* m_pData;	// dynamic array of data. Will be pointer to beginning of array
	size_t m_size; // how many elements in the array?

public:
	Document()
	{
		cout << " " << "Document Default Constructor" << endl;
	}

	// Copy Constructor. Called when we create a Document based on another
	Document(Document& other)
	{
		m_size = other.m_size;	// copying this is ok
		
		//m_pData = other.m_pData; // what happens originally by default
		// causes problems like double delete crash

		m_pData = new char[m_size];

		for (size_t i = 0; i < m_size; i++)
		{
			m_pData[i] = other.m_pData[i];
		}
	}
	
	//Constructs a document with its data filled out with size copies of data
	Document(size_t size, char data)
	{
		cout << " " << "Document Parameterized Constructor" << endl;
		// let us know how many elements our array will have
		m_size = size;

		// 'new' keyword says to find some space to put new data, then return the address of the
		// first element multipliied by the number of elements (size)
		// The block of memory is stored somewhere else. It doesn't live with the class.
		// It has a different lifetime, Instead we just get a pointer to the place it is stored
		m_pData = new char[size];	// points to address
		
		SetAllData(data);
	}

	void Cleanup()
	{
		cout << " " << "Deleting " << m_pData << endl;
		delete[] m_pData;
		m_pData = nullptr;
		m_size = 0;
	}
	

	// Destructor
	~Document()
	{
		cout << " " << "Document Default Destructor" << this << endl;
	}
	
	size_t GetSize() const	// guaranteed not to modify
	{
		return m_size;
	}

	// returns the element at index
	char GetDataAtIndex(size_t index) const
	{
		return m_pData[index];
	}

	// Sets all data to be the same in the array
	void SetAllData(char data)
	{
		for(size_t i = 0; i < m_size; i++)
		{
			m_pData[i] = data;
		}
	}
	
};

static class DocumentReader
{
public:

	static void PrintDocumentToConsole(const Document &docToPrint)
	{
		for (size_t i = 0; i < docToPrint.GetSize(); i++)
		{
			cout << docToPrint.GetDataAtIndex(i) << " ";
		}
		cout << endl;
	}

private:

};

int main()
{
	{
		// Declaring and constructing an instance of document. C++ knows it neeeds to create space for
		// a "Document" it will reserve space for aDOcumnet members.... which are m_pData and m_size
		Document doc(5, 'F');
		Document docCopy = doc;	// make a copy of original before anything else. Should be 5 F's

		DocumentReader::PrintDocumentToConsole(doc);

		cout << "\nDeclaring and initializing docMemberWise\n";
		
		Document docMemberWise(10, 'Q');
		DocumentReader::PrintDocumentToConsole(docMemberWise);

		cout << "Assigning with memberwise\n\n" << endl;

		// copy constructor not called here! This is memberise assignment. Not a constructor!
		// C++ Doesn't think it needs new memory for new documents. It's trying to just copy them in place
		docMemberWise = doc;	// this replaces docmemberwise's original pointer with a copy of doc's pointer
		// causing it to be lost to the ether FOREVER (memory leak)
		DocumentReader::PrintDocumentToConsole(docMemberWise);

		cout << "\nAssigning data in doc\n\n" << endl;
		doc.SetAllData('g');
		
		cout << "Contents in doc" << endl;
		DocumentReader::PrintDocumentToConsole(doc);

		cout << "Contents in docMemberWise" << endl;
		DocumentReader::PrintDocumentToConsole(docMemberWise);
		
		getchar();

		doc.Cleanup();
	}
	
	getchar();

	return 0;
}