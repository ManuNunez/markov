import numpy as np

def power_method(matrix, initial_guess, max_iterations=10000, eps=1e-9):
    current = initial_guess.copy()

    for _ in range(max_iterations):
        next_state = np.dot(matrix, current)

        norm = np.linalg.norm(next_state)
        next_state /= norm

        if np.allclose(next_state, current, atol=eps):
            return next_state

        current = next_state

    return current

def main():
    n = int(input())
    initial_state = np.array(list(map(float, input().split())))
    transition_matrix = np.array([list(map(float, input().split())) for _ in range(n)])

    steady_state = power_method(transition_matrix, initial_state)

    for val in steady_state:
        print(val, end=' ')

if __name__ == "__main__":
    main()
