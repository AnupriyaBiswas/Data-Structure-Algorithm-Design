import java.io.*;
public class Prog2002
{
    public static void main(String args[])throws IOException
    {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);

        int n, i;

        System.out.print("Enter Length of Array (n) : ");
        n = Integer.parseInt(br.readLine());
        int A[] = new int[n];

        for(i = 0; i < n; i++)
        {
            System.out.print("Enter Data : ");
            A[i] = Integer.parseInt(br.readLine());
        }
        int result = -1, low = 0, high = n -1;
        while(low <= high)
        {
            if(A[low] <= A[high])
            {
                result = A[high];
                break;
            }
            int mid = low + (high - low) /  2;
            if(((mid == 0) || (A[mid] > A[mid - 1])) && ((mid == (n - 1)) || (A[mid] > A[mid + 1])))
            {
                result = A[mid];
                break;
            }
            if(A[mid] > A[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        System.out.println(result);
    }
}