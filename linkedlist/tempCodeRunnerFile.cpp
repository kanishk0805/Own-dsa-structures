void print(Node *head)
{   
    int pos=0;
	Node *temp = head;
	while (temp != NULL && pos<9)
	{
		cout << temp->data << " ";
		temp = temp->next;
        pos++;
	}
	cout << endl;
}