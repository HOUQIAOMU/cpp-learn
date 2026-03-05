void swap(int &a, int &b)
{
    // use references to change the value of global variable.
    int var = b;
    b = a;
    a = var;
}

