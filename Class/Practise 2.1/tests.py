import subprocess
import sys
import os

def run_program(program_path, *args):
    result = subprocess.run([program_path, *args], capture_output=True, text=True)
    return result.stdout.strip(), result.stderr.strip()

def reset_environment():
    if os.path.exists("user_stats.txt"):
        os.remove("user_stats.txt")

def test_case_1(program_path):
    reset_environment()
    
    output, error = run_program(program_path, "Alice")
    assert output == "Welcome, Alice!", f"Expected 'Welcome, Alice!', but got '{output}'"
    
    output, error = run_program(program_path, "Alice")
    assert output == "Hello again (x2), Alice!", f"Expected 'Hello again (x2), Alice!', but got '{output}'"
    print("Test Case 1 Passed")

def test_case_2(program_path):
    reset_environment()
    
    run_program(program_path, "Bob")
    run_program(program_path, "Bob")
    
    output, error = run_program(program_path, "Bob", "delete")
    assert output == "Statistics for Bob have been reset.", f"Expected 'Statistics for Bob have been reset.', but got '{output}'"
    
    output, error = run_program(program_path, "Bob")
    assert output == "Welcome, Bob!", f"Expected 'Welcome, Bob!', but got '{output}'"
    print("Test Case 2 Passed")

def test_case_3(program_path):
    reset_environment()
    
    run_program(program_path, "Charlie")
    run_program(program_path, "Dana")
    
    output, error = run_program(program_path, "bread")
    assert output == "All user history has been exterminated!", f"Expected 'All user history has been exterminated!', but got '{output}'"
    
    output, error = run_program(program_path, "Charlie")
    assert output == "Welcome, Charlie!", f"Expected 'Welcome, Charlie!', but got '{output}'"
    
    output, error = run_program(program_path, "Dana")
    assert output == "Welcome, Dana!", f"Expected 'Welcome, Dana!', but got '{output}'"
    print("Test Case 3 Passed")

def test_case_4(program_path):
    reset_environment()
    
    result = subprocess.run([program_path], capture_output=True, text=True)
    assert "Usage: ./hello <name> [delete]"
    
    result = subprocess.run([program_path, "Too", "Many", "Args"], capture_output=True, text=True)
    assert "Usage: ./hello <name> [delete]"
    print("Test Case 4 Passed")

def test_case_5(program_path):
    reset_environment()
    
    run_program(program_path, "Eve")
    run_program(program_path, "Frank")
    
    output, error = run_program(program_path, "Eve")
    assert output == "Hello again (x2), Eve!", f"Expected 'Hello again (x2), Eve!', but got '{output}'"
    
    output, error = run_program(program_path, "Frank")
    assert output == "Hello again (x2), Frank!", f"Expected 'Hello again (x2), Frank!', but got '{output}'"
    print("Test Case 5 Passed")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python test_script.py <path_to_cpp_executable>")
        sys.exit(1)
    
    program_path = sys.argv[1]
    
    if not os.path.isfile(program_path):
        print(f"Error: The specified file '{program_path}' does not exist.")
        sys.exit(1)
    
    test_case_1(program_path)
    test_case_2(program_path)
    test_case_3(program_path)
    test_case_4(program_path)
    test_case_5(program_path)
    
    reset_environment()
