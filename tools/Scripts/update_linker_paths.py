import sys
import os

def update_linker_paths(linker_script_path, asm_dir, src_dir):
    """
    Update the paths in the linker script by replacing specific directories with the build directory.
    
    Parameters:
    - linker_script_path: The path to the linker script.
    - asm_dir: The directory where assembly files are located (to replace in the linker script).
    - src_dir: The directory where source files are located (to replace in the linker script).

    This function will:
    - Replace 'build/$(asm_dir)/' with 'build/'
    - Replace 'build/$(src_dir)/' with 'build/'
    """
    try:
        # Read the linker script content
        with open(linker_script_path, 'r') as file:
            content = file.read()

        # Replace the paths in the content
        content = content.replace(f'build/{asm_dir}/', 'build/')
        content = content.replace(f'build/{src_dir}/', 'build/')

        # Write the updated content back to the linker script file
        with open(linker_script_path, 'w') as file:
            file.write(content)

        print(f"\nLinker script paths updated successfully. Changes saved to {linker_script_path}")

    except FileNotFoundError:
        print(f"Error: The linker script at {linker_script_path} was not found.")
    except Exception as e:
        print(f"An error occurred: {str(e)}")

def main():
    if len(sys.argv) != 4:
        print("Usage: python update_linker_paths.py <linker_script_path> <asm_dir> <src_dir>")
        sys.exit(1)

    # Get the command-line arguments
    linker_script_path = sys.argv[1]
    asm_dir = sys.argv[2]
    src_dir = sys.argv[3]

    # Update the linker script paths
    update_linker_paths(linker_script_path, asm_dir, src_dir)

if __name__ == "__main__":
    main()
