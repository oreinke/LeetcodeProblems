int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int i, j, tank;

    for (i = 0; i < gasSize; i++)
    {
        tank = 0;
        for (j = 0; j < gasSize; j++)
        {
            tank += gas[(i + j) % gasSize];
            if ((tank -= cost[(i + j) % gasSize]) < 0)
            {
                i = (i + j);
                break;
            }
        }
        if (j == gasSize)
            return i;
    }

    return -1;
}