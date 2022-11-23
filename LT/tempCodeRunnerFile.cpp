 init();
    while (dem != m)
    {
        a = to_string(i);
        cout << seq[L - a.length()] + a << endl;
        if (!visited[i])
            dem++;
        i++;
    }