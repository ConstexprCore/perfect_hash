// GENERATED: 40 fully-qualified Java class names (33-62 chars) + 20 misses
#pragma once
#include <array>
#include <string_view>
inline constexpr std::array<std::string_view, 40> fqcn_keys = {
    "java.util.concurrent.ConcurrentHashMap",
    "java.util.concurrent.ConcurrentLinkedQueue",
    "java.util.concurrent.CopyOnWriteArrayList",
    "java.util.concurrent.atomic.AtomicInteger",
    "java.util.concurrent.atomic.AtomicLongArray",
    "java.util.concurrent.locks.ReentrantReadWriteLock",
    "java.util.concurrent.ScheduledThreadPoolExecutor",
    "java.util.concurrent.CompletableFuture",
    "java.util.concurrent.ThreadPoolExecutor",
    "java.util.concurrent.LinkedBlockingQueue",
    "java.util.function.BiFunction",
    "java.util.function.ToLongFunction",
    "java.util.stream.Collectors",
    "java.util.stream.IntStream",
    "java.util.regex.PatternSyntaxException",
    "java.lang.reflect.InvocationTargetException",
    "java.lang.reflect.ParameterizedType",
    "java.lang.invoke.MethodHandles",
    "java.lang.ref.WeakReference",
    "java.io.ByteArrayOutputStream",
    "java.io.ObjectInputStream",
    "java.nio.channels.AsynchronousSocketChannel",
    "java.nio.charset.StandardCharsets",
    "java.nio.file.attribute.BasicFileAttributes",
    "java.net.http.HttpClient",
    "java.security.MessageDigest",
    "java.security.spec.PKCS8EncodedKeySpec",
    "java.time.format.DateTimeFormatter",
    "java.time.temporal.ChronoUnit",
    "javax.crypto.spec.SecretKeySpec",
    "org.apache.commons.lang3.StringUtils",
    "org.apache.commons.collections4.MultiValuedMap",
    "org.springframework.context.ApplicationContext",
    "org.springframework.web.bind.annotation.RequestMapping",
    "org.springframework.beans.factory.annotation.Autowired",
    "com.fasterxml.jackson.databind.ObjectMapper",
    "com.fasterxml.jackson.annotation.JsonProperty",
    "com.google.common.collect.ImmutableList",
    "com.google.common.util.concurrent.ListenableFuture",
    "io.netty.channel.socket.nio.NioSocketChannel"
};
inline constexpr std::array<std::string_view, 20> fqcn_miss_keys = {
    "java.util.concurrent.ConcurrentSkipListMap",
    "java.util.concurrent.ForkJoinPool",
    "java.util.concurrent.atomic.AtomicReference",
    "java.util.function.Supplier",
    "java.lang.reflect.Method",
    "java.io.FileInputStream",
    "java.nio.ByteBuffer",
    "java.time.ZonedDateTime",
    "org.apache.commons.io.FileUtils",
    "org.springframework.stereotype.Component",
    "com.fasterxml.jackson.core.JsonParser",
    "com.google.common.base.Preconditions",
    "io.netty.buffer.ByteBuf",
    "javax.servlet.http.HttpServletRequest",
    "java.util.concurrent.ConcurrentHashMap$Node",
    "java.util.concurrent.ConcurrentHashMa",
    "org.springframework.web.bind.annotation.RequestMappings",
    "com.google.common.collect.ImmutableLists",
    "java.util.stream.Collector",
    "java.security.MessageDigests"
};
#define FQCN_KV_LIST \
    ConstexprCore::kv<"java.util.concurrent.ConcurrentHashMap", 0>, \
    ConstexprCore::kv<"java.util.concurrent.ConcurrentLinkedQueue", 1>, \
    ConstexprCore::kv<"java.util.concurrent.CopyOnWriteArrayList", 2>, \
    ConstexprCore::kv<"java.util.concurrent.atomic.AtomicInteger", 3>, \
    ConstexprCore::kv<"java.util.concurrent.atomic.AtomicLongArray", 4>, \
    ConstexprCore::kv<"java.util.concurrent.locks.ReentrantReadWriteLock", 5>, \
    ConstexprCore::kv<"java.util.concurrent.ScheduledThreadPoolExecutor", 6>, \
    ConstexprCore::kv<"java.util.concurrent.CompletableFuture", 7>, \
    ConstexprCore::kv<"java.util.concurrent.ThreadPoolExecutor", 8>, \
    ConstexprCore::kv<"java.util.concurrent.LinkedBlockingQueue", 9>, \
    ConstexprCore::kv<"java.util.function.BiFunction", 10>, \
    ConstexprCore::kv<"java.util.function.ToLongFunction", 11>, \
    ConstexprCore::kv<"java.util.stream.Collectors", 12>, \
    ConstexprCore::kv<"java.util.stream.IntStream", 13>, \
    ConstexprCore::kv<"java.util.regex.PatternSyntaxException", 14>, \
    ConstexprCore::kv<"java.lang.reflect.InvocationTargetException", 15>, \
    ConstexprCore::kv<"java.lang.reflect.ParameterizedType", 16>, \
    ConstexprCore::kv<"java.lang.invoke.MethodHandles", 17>, \
    ConstexprCore::kv<"java.lang.ref.WeakReference", 18>, \
    ConstexprCore::kv<"java.io.ByteArrayOutputStream", 19>, \
    ConstexprCore::kv<"java.io.ObjectInputStream", 20>, \
    ConstexprCore::kv<"java.nio.channels.AsynchronousSocketChannel", 21>, \
    ConstexprCore::kv<"java.nio.charset.StandardCharsets", 22>, \
    ConstexprCore::kv<"java.nio.file.attribute.BasicFileAttributes", 23>, \
    ConstexprCore::kv<"java.net.http.HttpClient", 24>, \
    ConstexprCore::kv<"java.security.MessageDigest", 25>, \
    ConstexprCore::kv<"java.security.spec.PKCS8EncodedKeySpec", 26>, \
    ConstexprCore::kv<"java.time.format.DateTimeFormatter", 27>, \
    ConstexprCore::kv<"java.time.temporal.ChronoUnit", 28>, \
    ConstexprCore::kv<"javax.crypto.spec.SecretKeySpec", 29>, \
    ConstexprCore::kv<"org.apache.commons.lang3.StringUtils", 30>, \
    ConstexprCore::kv<"org.apache.commons.collections4.MultiValuedMap", 31>, \
    ConstexprCore::kv<"org.springframework.context.ApplicationContext", 32>, \
    ConstexprCore::kv<"org.springframework.web.bind.annotation.RequestMapping", 33>, \
    ConstexprCore::kv<"org.springframework.beans.factory.annotation.Autowired", 34>, \
    ConstexprCore::kv<"com.fasterxml.jackson.databind.ObjectMapper", 35>, \
    ConstexprCore::kv<"com.fasterxml.jackson.annotation.JsonProperty", 36>, \
    ConstexprCore::kv<"com.google.common.collect.ImmutableList", 37>, \
    ConstexprCore::kv<"com.google.common.util.concurrent.ListenableFuture", 38>, \
    ConstexprCore::kv<"io.netty.channel.socket.nio.NioSocketChannel", 39>
#define FQCN_FROZEN_LIST \
    {"java.util.concurrent.ConcurrentHashMap", 0}, \
    {"java.util.concurrent.ConcurrentLinkedQueue", 1}, \
    {"java.util.concurrent.CopyOnWriteArrayList", 2}, \
    {"java.util.concurrent.atomic.AtomicInteger", 3}, \
    {"java.util.concurrent.atomic.AtomicLongArray", 4}, \
    {"java.util.concurrent.locks.ReentrantReadWriteLock", 5}, \
    {"java.util.concurrent.ScheduledThreadPoolExecutor", 6}, \
    {"java.util.concurrent.CompletableFuture", 7}, \
    {"java.util.concurrent.ThreadPoolExecutor", 8}, \
    {"java.util.concurrent.LinkedBlockingQueue", 9}, \
    {"java.util.function.BiFunction", 10}, \
    {"java.util.function.ToLongFunction", 11}, \
    {"java.util.stream.Collectors", 12}, \
    {"java.util.stream.IntStream", 13}, \
    {"java.util.regex.PatternSyntaxException", 14}, \
    {"java.lang.reflect.InvocationTargetException", 15}, \
    {"java.lang.reflect.ParameterizedType", 16}, \
    {"java.lang.invoke.MethodHandles", 17}, \
    {"java.lang.ref.WeakReference", 18}, \
    {"java.io.ByteArrayOutputStream", 19}, \
    {"java.io.ObjectInputStream", 20}, \
    {"java.nio.channels.AsynchronousSocketChannel", 21}, \
    {"java.nio.charset.StandardCharsets", 22}, \
    {"java.nio.file.attribute.BasicFileAttributes", 23}, \
    {"java.net.http.HttpClient", 24}, \
    {"java.security.MessageDigest", 25}, \
    {"java.security.spec.PKCS8EncodedKeySpec", 26}, \
    {"java.time.format.DateTimeFormatter", 27}, \
    {"java.time.temporal.ChronoUnit", 28}, \
    {"javax.crypto.spec.SecretKeySpec", 29}, \
    {"org.apache.commons.lang3.StringUtils", 30}, \
    {"org.apache.commons.collections4.MultiValuedMap", 31}, \
    {"org.springframework.context.ApplicationContext", 32}, \
    {"org.springframework.web.bind.annotation.RequestMapping", 33}, \
    {"org.springframework.beans.factory.annotation.Autowired", 34}, \
    {"com.fasterxml.jackson.databind.ObjectMapper", 35}, \
    {"com.fasterxml.jackson.annotation.JsonProperty", 36}, \
    {"com.google.common.collect.ImmutableList", 37}, \
    {"com.google.common.util.concurrent.ListenableFuture", 38}, \
    {"io.netty.channel.socket.nio.NioSocketChannel", 39}
#define FQCN_KRONUZ_LIST \
    h("java.util.concurrent.ConcurrentHashMap"), \
    h("java.util.concurrent.ConcurrentLinkedQueue"), \
    h("java.util.concurrent.CopyOnWriteArrayList"), \
    h("java.util.concurrent.atomic.AtomicInteger"), \
    h("java.util.concurrent.atomic.AtomicLongArray"), \
    h("java.util.concurrent.locks.ReentrantReadWriteLock"), \
    h("java.util.concurrent.ScheduledThreadPoolExecutor"), \
    h("java.util.concurrent.CompletableFuture"), \
    h("java.util.concurrent.ThreadPoolExecutor"), \
    h("java.util.concurrent.LinkedBlockingQueue"), \
    h("java.util.function.BiFunction"), \
    h("java.util.function.ToLongFunction"), \
    h("java.util.stream.Collectors"), \
    h("java.util.stream.IntStream"), \
    h("java.util.regex.PatternSyntaxException"), \
    h("java.lang.reflect.InvocationTargetException"), \
    h("java.lang.reflect.ParameterizedType"), \
    h("java.lang.invoke.MethodHandles"), \
    h("java.lang.ref.WeakReference"), \
    h("java.io.ByteArrayOutputStream"), \
    h("java.io.ObjectInputStream"), \
    h("java.nio.channels.AsynchronousSocketChannel"), \
    h("java.nio.charset.StandardCharsets"), \
    h("java.nio.file.attribute.BasicFileAttributes"), \
    h("java.net.http.HttpClient"), \
    h("java.security.MessageDigest"), \
    h("java.security.spec.PKCS8EncodedKeySpec"), \
    h("java.time.format.DateTimeFormatter"), \
    h("java.time.temporal.ChronoUnit"), \
    h("javax.crypto.spec.SecretKeySpec"), \
    h("org.apache.commons.lang3.StringUtils"), \
    h("org.apache.commons.collections4.MultiValuedMap"), \
    h("org.springframework.context.ApplicationContext"), \
    h("org.springframework.web.bind.annotation.RequestMapping"), \
    h("org.springframework.beans.factory.annotation.Autowired"), \
    h("com.fasterxml.jackson.databind.ObjectMapper"), \
    h("com.fasterxml.jackson.annotation.JsonProperty"), \
    h("com.google.common.collect.ImmutableList"), \
    h("com.google.common.util.concurrent.ListenableFuture"), \
    h("io.netty.channel.socket.nio.NioSocketChannel")
