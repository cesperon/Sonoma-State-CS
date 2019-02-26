

def get_input(filename):

    f = open(filename)
    return [int(x) for x in f]


def build_table(C, V, table):

    for i in range(len(V) + 1):
        row = []
        for j in range(C + 1):
            row.append(0)
        table.append(row)
