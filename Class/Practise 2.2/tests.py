import subprocess
import os
import sys
import filecmp

def run_test(executable, input_file, favorite_color, expected_output_file, actual_output_file, expected_console_output, expect_fail=False):
    print(f"Running test with input file: {input_file}")
    process = subprocess.Popen([executable], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    
    # Simulate user input
    user_input = f"{input_file}\n{favorite_color}\n{actual_output_file}\n"
    stdout, stderr = process.communicate(user_input)

    if expect_fail:
        # If we expect the test to fail, check stdout for error messages
        if stdout.strip() == expected_console_output:
            print(f"Expected error received: {stdout.strip()}")
            return True
        else:
            print("Expected failure but got none or unexpected error.")
            print(f"Expected: {expected_console_output}")
            print(f"Got: {stdout.strip()}")
            return False
    else:
        if stderr:
            print(f"Unexpected error: {stderr.strip()}")
            return False

        # Check if the actual output file was created
        if not os.path.exists(actual_output_file):
            print(f"Actual output file not found: {actual_output_file}")
            return False

        # Compare actual output file with expected output file
        result = filecmp.cmp(expected_output_file, actual_output_file, shallow=False)
        print(f"Comparison result for {actual_output_file}: {result}")
        
        # Compare stdout with expected console output
        if stdout.strip() != expected_console_output.strip():
            print(f"Expected console output not received. Got:\n{stdout.strip()}")
            return False
        
        return result

def test_case_1(executable):
    input_file = os.path.join("images", "test_input_1.txt")
    favorite_color = "32 32 32" # Grey
    expected_output_file = os.path.join("images", "expected_output_1.txt")
    actual_output_file = os.path.join("images", "actual_output_1.txt")
    expected_console_output = (
        "Enter input file name: \n"
        "Enter your favorite color (r g b): \n"
        "Enter output file name: \n"
        f"Image processing complete. Output written to {actual_output_file}."
    )

    print("Running test case 1")
    assert run_test(executable, input_file, favorite_color, expected_output_file, actual_output_file, expected_console_output), "Test case 1 failed"

def test_case_2(executable):
    input_file = os.path.join("images", "test_input_2.txt")
    favorite_color = "255 0 0" # Red
    expected_output_file = os.path.join("images", "expected_output_2.txt")
    actual_output_file = os.path.join("images", "actual_output_2.txt")
    expected_console_output = (
        "Enter input file name: \n"
        "Enter your favorite color (r g b): \n"
        "Enter output file name: \n"
        f"Image processing complete. Output written to {actual_output_file}."
    )

    print("Running test case 2")
    assert run_test(executable, input_file, favorite_color, expected_output_file, actual_output_file, expected_console_output), "Test case 2 failed"

def test_case_3(executable):
    input_file = os.path.join("images", "test_input_3.txt")
    favorite_color = "0 0 255" # Blue
    expected_output_file = os.path.join("images", "expected_output_3.txt")
    actual_output_file = os.path.join("images", "actual_output_3.txt")
    expected_console_output = (
        "Enter input file name: \n"
        "Enter your favorite color (r g b): \n"
        "Enter output file name: \n"
        f"Image processing complete. Output written to {actual_output_file}."
    )

    print("Running test case 3")
    assert run_test(executable, input_file, favorite_color, expected_output_file, actual_output_file, expected_console_output), "Test case 3 failed"

def test_case_4(executable):
    input_file = os.path.join("images", "test_input_4.txt")
    favorite_color = "255 255 0"
    expected_console_output = (
        "Enter input file name: \n"
        "Enter your favorite color (r g b): \n"
        "Enter output file name: \n"
        f"Invalid input format: not enough lines."
    )

    print("Running test case 4")
    # File with invalid format (less lines)
    # Expect this to fail due to invalid format 
    assert run_test(executable, input_file, favorite_color, "", "", expected_console_output, expect_fail=True), "Test case 4 did not fail as expected"

def test_case_5(executable):
    input_file = os.path.join("images", "test_input_5.txt")
    favorite_color = "255 0 0"
    expected_console_output = (
        "Enter input file name: \n"
        "Enter your favorite color (r g b): \n"
        "Enter output file name: \n"
        f"Invalid input format at line 1, pixel 1."
    )

    print("Running test case 5")
    # File with invalid format (incorrect pixel format)
    # Expect this to fail due to invalid format
    assert run_test(executable, input_file, favorite_color, "", "", expected_console_output, expect_fail=True), "Test case 5 did not fail as expected"

def main(executable):
    test_case_1(executable)
    test_case_2(executable)
    test_case_3(executable)
    test_case_4(executable)
    test_case_5(executable)
    print("All tests passed.")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python test_script.py <executable>")
        sys.exit(1)

    executable = sys.argv[1]

    main(executable)
