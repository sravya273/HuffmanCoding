# HuffmanCoding
Implementation of Huffman coding with binary trees in C++  
Huffman code is a type of optimal prefix code that is commonly used for lossless data compression.  
The main idea is to transform plain input into variable-length code. As in other entropy encoding methods, more common symbols are generally represented using fewer bits than less common symbols. The easiest way to understand how to create Huffman tree is to analyze following steps:  
1.Scan text for symbols (e.g. 1-byte characters) and calculate their frequency of occurrence. Symbol value with its count of occurrences is a single leaf.  
Start a loop.
2.Find two smallest probability nodes and combine them into single node.  
3.Remove those two nodes from list and insert combined one.  
4.Repeat the loop until the list has only single node.  
5.This last single node represent a huffman tree.  
