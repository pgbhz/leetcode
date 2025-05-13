import os
import sys


def find_problem_location(problem_number):
    base_path = os.path.dirname(os.path.abspath(__file__))
    for root, dirs, files in os.walk(base_path):
        for file in files:
            if file.startswith(f"{problem_number}_"):
                relative_path = os.path.relpath(root, base_path)
                return f"Problem {problem_number} is located in folder: {relative_path}"
    return f"Problem {problem_number} not found in the project."


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python find_problem_location.py <problem_number>")
        sys.exit(1)

    problem_number = sys.argv[1].strip()
    if problem_number.isdigit():
        print(find_problem_location(problem_number))
    else:
        print("Please enter a valid numerical problem number.")
