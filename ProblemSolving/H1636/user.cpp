#define DISK_SIZE  20000
#define BUF_SIZE   64
#define MAX_FILE   10

static int disk[DISK_SIZE];

extern int getdiskSize();
extern int readDisk(int* buf, int addr, int size);
extern int move(int from, int to, int size);

int disk_size;
int zero_size;
int zero_idx;

void myMove(int from, int to, int size)
{
	for (int i = 0; i < size; i++)
	{
		disk[to + i] = disk[from + i];
		disk[from + i] = 0;
	}
	move(from, to, size);
}

void moveZero()
{
	int s = 0;
	int e = disk_size - 1;

	while (true)
	{
		while (disk[s]) s++;
		while (!disk[e]) e--;
		if (s >= e)
			break;

		int size = 0;

		for (; size < BUF_SIZE; size++)
		{
			if (disk[s + size] || disk[e - size] == 0)
				break;
		}
		myMove(e - size + 1, s, size);
	}

	zero_idx = s;
	zero_size = disk_size - s;
	if (zero_size > BUF_SIZE) zero_size = BUF_SIZE;
}

int moveVal(int start_idx)
{
	int s = start_idx;
	int e = zero_idx - 1;

	int input = disk[start_idx];

	while (true)
	{
		while (disk[s] == input) s++;
		while (disk[e] != input) e--;

		if (s >= e)
			break;

		int size = 0;
		for (; size < zero_size; size++)
		{
			if (disk[s + size] == input || disk[e - size] != input)
				break;
		}

		myMove(s, zero_idx, size);
		myMove(e - size + 1, s, size);
		myMove(zero_idx, e - size + 1, size);
	}
	return s;
}

void defragment()
{
	disk_size = getdiskSize();
	readDisk(disk, 0, disk_size);

	moveZero();

	int i = 0;
	while (disk[i] != 0) {
		i = moveVal(i);
	}
}
