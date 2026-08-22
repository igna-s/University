#!/usr/bin/env python3
"""
Python Code Validator for n8n workflow
Validates Python syntax using AST parser
"""

import sys
import json
import ast
import traceback

def validate_python_code(code):
    """
    Validate Python code syntax using AST parser
    
    Args:
        code (str): Python code to validate
        
    Returns:
        dict: Validation result
    """
    try:
        # Check for empty code
        if not code or not code.strip():
            return {
                'valid': False, 
                'error': 'Empty code snippet', 
                'method': 'python_ast',
                'details': {'empty_code': True}
            }
        
        # Parse with AST
        ast.parse(code)
        
        return {
            'valid': True, 
            'error': None, 
            'method': 'python_ast',
            'details': {
                'ast_valid': True,
                'code_length': len(code),
                'lines_count': len(code.splitlines())
            }
        }

    except SyntaxError as e:
        return {
            'valid': False, 
            'error': f'SyntaxError: Line {e.lineno}: {e.msg}', 
            'method': 'python_ast',
            'details': {
                'syntax_error': True,
                'line_number': e.lineno,
                'error_message': e.msg,
                'offset': getattr(e, 'offset', None),
                'text': getattr(e, 'text', None)
            }
        }
    except Exception as e:
        return {
            'valid': False, 
            'error': f'Validation error: {str(e)}', 
            'method': 'python_ast',
            'details': {
                'general_error': True, 
                'error_type': type(e).__name__,
                'traceback': traceback.format_exc()
            }
        }

def main():
    """Main execution function"""
    try:
        # Read input from stdin
        input_data = sys.stdin.read().strip()
        
        if not input_data:
            # Try to get from command line arguments
            if len(sys.argv) > 1:
                input_data = sys.argv[1]
            else:
                print(json.dumps({
                    'valid': False,
                    'error': 'No input data provided',
                    'method': 'external_script',
                    'details': {'no_input': True}
                }))
                sys.exit(1)
            
        # Parse JSON input
        data = json.loads(input_data)
        code = data.get('code', '')
        
        # Validate code
        result = validate_python_code(code)
        
        # Output result as JSON
        print(json.dumps(result))
        
    except json.JSONDecodeError as e:
        print(json.dumps({
            'valid': False,
            'error': f'Invalid JSON input: {str(e)}',
            'method': 'external_script',
            'details': {'json_error': True}
        }))
        sys.exit(1)
    except Exception as e:
        print(json.dumps({
            'valid': False,
            'error': f'Script execution error: {str(e)}',
            'method': 'external_script',
            'details': {
                'script_error': True,
                'error_type': type(e).__name__,
                'traceback': traceback.format_exc()
            }
        }))
        sys.exit(1)

if __name__ == "__main__":
    main()