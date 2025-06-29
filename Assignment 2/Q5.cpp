//huffman coding
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Node structure for Huffman Tree
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char ch, int freq) {
        this->ch = ch;
        this->freq = freq;
        left = right = nullptr;
    }
};

// Compare function for priority queue (min-heap)
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Function to generate Huffman Codes
void generateCodes(Node* root, string code, unordered_map<char, string> &huffmanCode) {
    if (!root) return;

    if (!root->left && !root->right)
        huffmanCode[root->ch] = code;

    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

// Function to build the Huffman Tree
Node* buildHuffmanTree(unordered_map<char, int> &freq) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (auto pair : freq)
        pq.push(new Node(pair.first, pair.second));

    while (pq.size() > 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();
        Node *merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }

    return pq.top();
}

// Function to decode the encoded string
string decodeHuffman(Node* root, string encodedStr) {
    string result = "";
    Node* current = root;

    for (char bit : encodedStr) {
        if (bit == '0') current = current->left;
        else current = current->right;

        if (!current->left && !current->right) {
            result += current->ch;
            current = root;
        }
    }

    return result;
}

int main() {
    string text;
    cout << "Enter the string: ";
    getline(cin, text);

    unordered_map<char, int> freq;
    for (char ch : text) freq[ch]++;

    Node* root = buildHuffmanTree(freq);

    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    cout << "\nHuffman Codes:\n";
    for (auto pair : huffmanCode)
        cout << pair.first << ": " << pair.second << '\n';

    string encodedStr = "";
    for (char ch : text)
        encodedStr += huffmanCode[ch];

    cout << "\nEncoded String:\n" << encodedStr << endl;

    string decodedStr = decodeHuffman(root, encodedStr);
    cout << "\nDecoded String:\n" << decodedStr << endl;
}