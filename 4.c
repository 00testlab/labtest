			else
					printf("\nBuffer is empty\n");
				break;
			case 3:
				return;
			default:
			printf("\n Enter the correct choice\n");
		}
	}
}
void producer()
{
	mutex=wait(mutex);
	full=signal(full);
	empty=wait(empty);
	x++;
	printf("\n Producer produced product %d\n",x);
	mutex=signal(mutex);
}
void consumer()
{
	mutex=wait(mutex);
	full=wait(full);
	empty=signal(empty);
	
	printf("\n Consumer consumed product %d\n",x);
	x--;
	mutex=signal(mutex);
}
int wait(int s)
{	return --s;
}
int signal(int s)
{	return ++s;
}
