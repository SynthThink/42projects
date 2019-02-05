/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:08:10 by malluin           #+#    #+#             */
/*   Updated: 2018/11/12 11:55:05 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_putlst(t_list *elem)
{
	printf("Content: %d %p\n", *(int *)(elem->content), elem);
}

t_list	*ft_lstcpy(t_list *elem)
{
	t_list *cpy;

	if(!(cpy = (t_list *)malloc(sizeof(t_list))))
		return (0);
	cpy->content_size = elem->content_size * 2;
	if(!(cpy->content = (void *)malloc(cpy->content_size)))
		return (0);
	*(int *)(cpy->content) = *(int *)(elem->content) * 2;
	cpy->next = 0;
	return (cpy);
}

void	del(void * elem, size_t size)
{
	size = 0;
	//if (elem)
	free(elem);
}

int	main()
{
	t_list **newlist;
	t_list *node1;
	t_list *node2;
	void const *ptr;
	const int i = 42;
	const int j = 24;
	const int k = 12;

	/*           LSTNEW   */
	printf("FT_LSTNEW\n");
	ptr = &i;
	newlist = &node1;
	node1 = ft_lstnew(ptr, sizeof(int));
	printf("Tete de liste %d\n", *((int *)((*newlist)->content)));

	//           LSTADD    
	printf("\nFT_LSTADD\n");
	ptr = &j;
	node2 = ft_lstnew(ptr, sizeof(int));
	ft_lstadd(newlist, node2);
	ptr = &k;
	node2 = ft_lstnew(ptr, sizeof(int));
	ft_lstadd(newlist, node2);
	printf("Tete de liste %d\n", *((int *)((*newlist)->content)));
	printf("2eme chainon %d\n", *(int *)((*newlist)->next->content));
	printf("3eme chainon %d\n", *(int *)(((*newlist)->next)->next->content));

	//           LSTITER   
	printf("\nFT_LSTITER\n");
	ft_lstiter(*newlist, ft_putlst);

	//			LSTMAP   
	printf("\n FT_LSTMAP \n");
	t_list *modlist;
	modlist = ft_lstmap(*newlist, ft_lstcpy);
	printf("NEWLIST\n");
	ft_lstiter(*newlist, ft_putlst);

	printf("MODIFLIST\n");
	ft_lstiter(modlist, ft_putlst);

	//			LSTDELONE
	printf("\n FT_LSTDELONE \n");
	printf("LIBERE DEUXIEME MAILLON\n");
	ft_lstdelone(&(modlist->next), del);
	ft_lstiter(modlist, ft_putlst);
	printf("MUST BE 0 ===> %p\n", modlist->next);

	printf("Liste 1 maillon\n");
	t_list *test1;
	test1 = malloc(sizeof(t_list));
	printf("%p\n", test1);
	test1->content = malloc(sizeof(int));
	ft_lstdelone(&test1, del);	
	if (test1 == NULL) 
		printf("Apres del: %p OK NULL", test1);
	else
		printf("%p ERREUR not NULL", test1);

	//    		LSTDEL
	printf("\n\n FT_LSTDEL\n");
	printf("Libere chaine\n");
	ft_lstiter(*newlist, ft_putlst);
	ft_lstdel(newlist, del);
	ft_lstiter(*newlist, ft_putlst);
	if ((*newlist) == NULL) 
		printf("Apres del: %p OK NULL\n\n", *newlist);
	else
		printf("%p ERREUR not NULL\n\n", *newlist);

	ft_lstiter(modlist, ft_putlst);
	ft_lstdel(&modlist, del);
	ft_lstiter(modlist, ft_putlst);
	if ((modlist) == NULL) 
		printf("Apres del: %p OK NULL\n", modlist);
	else
		printf("%p ERREUR not NULL\n", modlist);


	return (0);
}
