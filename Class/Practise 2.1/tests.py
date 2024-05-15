import subprocess
import sys
import os

def run_program(program_path, *args):
    result = subprocess.run([program_path, *args], capture_output=True, text=True)
    return result.stdout.strip(), result.stderr.strip()

def test_case_1(program_path):
    # Step 1: Ensure fresh start
    if os.path.exists("user_stats.txt"):
        os.remove("user_stats.txt")
    
    # Step 2: Run with "Alice"
    output, error = run_program(program_path, "Alice")
    assert output == "Welcome, Alice!"
    
    # Step 3: Run again with "Alice"
    output, error = run_program(program_path, "Alice")
    assert output == "Hello again(x2), Alice!"
    print("Test Case 1 Passed")

def test_case_2(program_path):
    # Step 1: Run with "Bob"
    run_program(program_path, "Bob")
    
    # Step 2: Run again with "Bob"
    run_program(program_path, "Bob")
    
    # Step 3: Reset statistics
    output, error = run_program(program_path, "Bob", "delete")
    assert output == "Statistics for Bob have been reset."
    
    # Step 4: Run again with "Bob"
    output, error = run_program(program_path, "Bob")
    assert output == "Welcome, Bob!"
    print("Test Case 2 Passed")

def test_case_3(program_path):
    # Step 1: Run with "Charlie"
    run_program(program_path, "Charlie")
    
    # Step 2: Run with "Dana"
    run_program(program_path, "Dana")
    
    # Step 3: Clear all history
    output, error = run_program(program_path, "bread")
    assert output == "All user history has been exterminated!"
    
    # Step 4: Run again with "Charlie"
    output, error = run_program(program_path, "Charlie")
    assert output == "Welcome, Charlie!"
    
    # Step 5: Run again with "Dana"
    output, error = run_program(program_path, "Dana")
    assert output == "Welcome, Dana!"
    print("Test Case 3 Passed")

def test_case_4(program_path):
    # Step 1: Run without arguments
    result = subprocess.run([program_path], capture_output=True, text=True)
    assert "Usage: ./hello <name> [delete]"
    
    # Step 2: Run with too many arguments
    result = subprocess.run([program_path, "Too", "Many", "Args"], capture_output=True, text=True)
    assert "Usage: ./hello <name> [delete]"
    print("Test Case 4 Passed")

def test_case_5(program_path):
    # Step 1: Run with "Eve"
    run_program(program_path, "Eve")
    
    # Step 2: Run with "Frank"
    run_program(program_path, "Frank")
    
    # Step 3: Run again with "Eve"
    output, error = run_program(program_path, "Eve")
    assert output == "Hello again(x2), Eve!"
    
    # Step 4: Run again with "Frank"
    output, error = run_program(program_path, "Frank")
    assert output == "Hello again(x2), Frank!"
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
