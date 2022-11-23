char check(char board[3][3])
{
    // Check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == '.')
        {
            continue;
        }
        for (int j = 0; j < 3; j++)
        {
            char a = board[j][i];
            char b = board[0][i];
            if (a == b)
            {
                if (j == 2)
                {
                    return board[j][i];
                }
                continue;
            }
            break;
        }
    }

    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == '.')
        {
            continue;
        }
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == board[i][0])
            {
                if (j == 2)
                {
                    return board[i][j];
                }
                continue;
            }
            break;
        }
    }

    // Check diagonal (\)
    if (board[0][0] != '.')
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][i] == board[j][j])
                {
                    if (i == 1 && j == 2)
                    {
                        return board[i][i];
                    }
                    continue;
                }
                break;
            }
        }
    }

    // Check anti-diagonal (/)
    if (board[0][2] != '.' && board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[1][1] == board[2][0])
    {
        return board[0][2];
    }
    return '\0';
}

int main() {
    char board[3][3] = {
        {'.', 'O', '.'},
        {'.', 'O', '.'},
        {'.', 'O', '.'}
    };
    check(board);
}
