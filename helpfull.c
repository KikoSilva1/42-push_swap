	printf("Número de argumentos (argc): %d\n", argc);//to be removed
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }

	for (int i = 0; i < argc-1; i++) {
    printf("indexed_argv[%d] = %d\n", i, indexed_argv[i]);
    }

		for (int i = 0; i < size; i++) {
        printf("ordered_argv[%d] = %d\n", i, int_argv[i]);
    }
