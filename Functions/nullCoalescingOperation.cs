/*************************************************************************/
/* In C#, known as null-coalescing operator (??), it returns the         */
/* left-hand operand if the operand is not null; otherwise it returns    */
/* the right-hand operand.                                               */
/*                                                                       */
/* If you try to assign a nullable value type to a non-nullable value    */
/* type without using the ?? operator, you will generate a compile-time  */
/* error. If you use a cast, and the nullable value type is currently    */
/* undefined, an InvalidOperationException exception will be thrown.     */
/*                                                                       */
/* The result of a ?? operator is not considered to be a constant even   */
/* if both its arguments are constants.                                  */
/*************************************************************************/

// Null-Coalescing operator
  return (s ?? "default_value"); 

// Conditional Operator correspondence
  return (s != null ? s : "default_value"); 
  
// if-elsecorrespondence
  if (s != null)
    return s;
  else
    return "default_value"; 

/*************************************************************************/

// Simple use   
  int? x = null;
  int y = x ?? -1; // y = x, unless x is null, in which case y = -1
